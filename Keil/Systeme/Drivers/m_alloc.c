/******************************************************************************/
/* m_alloc.c: Memory allocator service                                        */
/*                                                                            */
/******************************************************************************/
/* This program is free software: you can redistribute it and/or modify       */
/*    it under the terms of the GNU General Public License as published by    */
/*    the Free Software Foundation, either version 3 of the License, or       */
/*    (at your option) any later version.                                     */
/*                                                                            */
/*    This program is distributed in the hope that it will be useful,         */
/*    but WITHOUT ANY WARRANTY; without even the implied warranty of          */
/*    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the           */
/*    GNU General Public License for more details.                            */
/*                                                                            */
/*    You should have received a copy of the GNU General Public License       */
/*    along with this program.  If not, see <http://www.gnu.org/licenses/>.   */
/******************************************************************************/

#include "stm32f30x.h"
#include "system.h"
#include "panic.h"

//uint32_t MALLOC_LowerBound=0x20000000;
//uint32_t MALLOC_UpperBound=0x20009000;

uint32_t MALLOC_LowerBound;
const uint32_t MALLOC_UpperBound = MALLOC_END_BASE;

#define EMPTY_TAG		0x00000000
#define ENDING_TAG	0xBAADF00D 
#define USED_TAG		0x000000FF
#define FILL_PATTERN 0xA5A5A5A5

struct ST_BLOCK_HEADER
{
	uint32_t tag;
	struct ST_BLOCK_HEADER* ptr;
};

typedef struct ST_BLOCK_HEADER BlockHeader;

void MALLOC_Init(uint32_t bound)
{
BlockHeader* ptr;
uint32_t *i;
	
	if ((bound>=MALLOC_INITIAL_BASE) && (bound<MALLOC_UpperBound))
	{
		if ((bound % 4) == 0) MALLOC_LowerBound=bound;
		else while (1);
	}
	else while (1);
	
	/* remplissage du buffer avec un pattern */
	for (i = (uint32_t *)MALLOC_LowerBound; i< (uint32_t *)MALLOC_UpperBound; i++)
	{
		*i = FILL_PATTERN;
	}
	
	/* Vu que la borne a bougé, on reset et on reinstalle un nouveau bloc a cette adresse */
	ptr = (BlockHeader*)bound;
	ptr->tag=ENDING_TAG;
	ptr->ptr=(BlockHeader*)0x0;
}

void* MALLOC_GetMemory(uint32_t size)
{
BlockHeader *ptr, *ptr2, *searchPtr;
char searchFinished;
uint32_t blockSize;
uint32_t desiredSize;
	
	ptr = (BlockHeader*)0x0;
	searchPtr = (BlockHeader*)MALLOC_LowerBound;
	searchFinished = 0;
	desiredSize = 2048+((size/4)*4);
	
	if ((size % 4) !=0)
	{
		desiredSize = desiredSize +4;
	}
	
	do
	{
		if (searchPtr->tag == ENDING_TAG)
		{
			/* on vient d'arriver à la fin de la liste chainée */
			/* Calcul si le reste de memoire est suffisant. Remarque: on compte 2 fois la taille de blocHeader
			   car il faudra rajouter un bloc terminal si la taille est suffisante 
			*/
			blockSize = MALLOC_UpperBound - (uint32_t)searchPtr;
			blockSize = blockSize - 2*sizeof (BlockHeader);
			
			/* Si la taille est suffisante, on sort avec le code 3 */
			if (blockSize>=desiredSize)
			{
				ptr = searchPtr;
				searchFinished=3;
			}
			else /* sinon, on sort avec le code 1 */
			{
				searchFinished=1;
			}
		}
		else if (searchPtr->tag == EMPTY_TAG)
		{
			/* Calcul de la taille du bloc libre, en comptant la taille d'un BlockHeader a rajouter */
			blockSize = (uint32_t)(searchPtr->ptr - searchPtr);
			blockSize = blockSize - sizeof(BlockHeader);
			
			/* si le bloc est exactement de la taille recherchée la recherche se termine avec le code 2*/
			if (blockSize==desiredSize)
			{
				ptr = searchPtr;
				searchFinished=2;
			}
			/* Si le bloc n'a pas exactement la taille demandée il faudra rajouter un blocHeader si la taille est 
			   suffisante. Dans ce cas, on calcul la taille du bloc en prenant en compte ce bloc a rajouter
				 On sort avec me code 3 */
			else if ((blockSize-sizeof(BlockHeader))>=desiredSize)
			{
				ptr = searchPtr;
				searchFinished=3;
			}
			else /* sinon, on passe au block d'apres */
			{
				searchPtr = searchPtr->ptr;
			}
		}
		else if (searchPtr->tag == USED_TAG)
		{
			/* on passe au bloc d'apres */
			searchPtr = searchPtr->ptr;
		}
		else 
		{
			PANIC_SoftwarePanic("Memory Corruption", "MALLOC is corrupted");
		}
		
		/* On verifie que notre pointeur de recherche est toujours bien dans la heap */
		if (searchPtr<(BlockHeader*)MALLOC_LowerBound) /* Si on est avant la heap: pb !*/
		{
			PANIC_SoftwarePanic("Memory Corruption", "MALLOC is outside heap");
		}
			
		if (searchPtr>=(BlockHeader*)MALLOC_UpperBound) /* si on sort de la heap par le haut: pas bien, mais ca veut dire
				                                                 qu'il n'y a pas de bloc dispo (code 1)*/
		{
			searchFinished=1;
		}
	} while (searchFinished==0);
	
	if (searchFinished != 1) /* Si on est sorti parcequ'un bloc libre a été trouvé */
	{
		if (searchFinished == 2) /* code 2 => pas de rajout de blocHeader */
		{
			ptr->tag = USED_TAG;
		}
		else /* searchFinished == 3 : code 3 => rajout d'un bloc header */
		{
			if (ptr->tag == ENDING_TAG)
			{
				ptr->tag = USED_TAG;
				ptr->ptr = (BlockHeader*)((uint32_t)ptr + desiredSize + sizeof (BlockHeader));
				
				ptr->ptr->tag= ENDING_TAG;
				ptr->ptr->ptr= (BlockHeader*)0x0;
			}
			else
			{
				ptr->tag = USED_TAG;
				ptr2 = ptr->ptr;
				
				ptr->ptr = (BlockHeader*)((uint32_t)ptr + desiredSize + sizeof (BlockHeader));
				
				ptr->ptr->tag= EMPTY_TAG;
				ptr->ptr->ptr= ptr2;
			}
		}
		
		ptr = ptr+1; /* on saute le blocHeader */
	}
	
	return (void*)ptr;
}

void MALLOC_FreeMemory(void* ptr)
{
BlockHeader *localPtr, *ptr2;
char searchFinished;
	
	if ((ptr <(void*)MALLOC_LowerBound) || (ptr >=(void*)MALLOC_UpperBound))
	{
		return;
	}
	
	localPtr = ptr;
	localPtr --; /* on remonte au niveau du bloc header */
	
	searchFinished =0;
	
	if (localPtr->tag == USED_TAG) 
	{
		/* on repasse le bloc à empty */
		localPtr->tag = EMPTY_TAG;
	}
	else if ((localPtr->tag != EMPTY_TAG) || (localPtr->tag != ENDING_TAG))
	{
		while (1); /* Gros probleme: le bloc header n'est pas marqué par un tag valide => jardinage !*/
	}
	
	localPtr = (BlockHeader*)MALLOC_LowerBound;
	ptr2 = (BlockHeader*)0x0;
	
	do
	{
		if (localPtr->tag == EMPTY_TAG)
		{
			if (ptr2 == 0) 
			{
				ptr2 = localPtr;
			}
		}
		else if (localPtr->tag == USED_TAG)
		{
			if (ptr2 != 0)
			{
				ptr2->ptr = localPtr;
			}
			
			ptr2 =0;
		}
		else if (localPtr->tag == ENDING_TAG)
		{
			searchFinished =1;
			
			if (ptr2 != 0)
			{
				ptr2->tag = ENDING_TAG;
				ptr2->ptr = 0x0;
			}
		}
		else
		{
			while (1); /* Gros probleme */
		}
		
		localPtr = localPtr->ptr;
		
	} while (searchFinished == 0);
}

