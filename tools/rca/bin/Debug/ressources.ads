-- 
-- Generated by rca 18/12/2017 10:11:42
--

pragma Ada_95;

with Insa;
with Insa.Graphics;
with Insa.Graphics.Images;
with Insa.Audio;
with Insa.Audio.Synthesizer;

use Insa.Graphics.Images;
use Insa.Audio.Synthesizer;

package ressources is

    pragma Warnings (Off);

	Sin : aliased constant SYNTH_WAVE :=
	(
		128,
		142,
		156,
		171,
		184,
		197,
		209,
		219,
		229,
		237,
		244,
		249,
		253,
		255,
		255,
		254,
		251,
		247,
		241,
		233,
		224,
		214,
		203,
		190,
		177,
		164,
		149,
		135,
		121,
		107,
		92,
		79,
		66,
		53,
		42,
		32,
		23,
		15,
		9,
		5,
		2,
		1,
		1,
		3,
		7,
		12,
		19,
		27,
		37,
		47,
		59,
		72,
		85,
		100,
		114
	);

	Sin_Access : SYNTH_WAVE_ACCESS := Sin'Access;

	Sqr : aliased constant SYNTH_WAVE :=
	(
		255,
		255,
		255,
		255,
		255,
		255,
		255,
		255,
		255,
		255,
		255,
		255,
		255,
		255,
		255,
		255,
		255,
		255,
		255,
		255,
		255,
		255,
		255,
		255,
		255,
		255,
		255,
		255,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,