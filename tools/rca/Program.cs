﻿//
//  Program.cs
//
//  Author:
//       DI MERCURIO Sebastien <dimercur@insa-toulouse.fr>
//
//  Copyright (c) 2016 INSA - GEI, Toulouse, France
//
//  This program is free software: you can redistribute it and/or modify
//  it under the terms of the GNU Lesser General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU Lesser General Public License for more details.
//
//  You should have received a copy of the GNU Lesser General Public License
//  along with this program.  If not, see <http://www.gnu.org/licenses/>.

using System;
using System.Text;
using System.Drawing;
using System.IO;

namespace rca
{
	class MainProgram
	{
		public static int Main(string[] args)
		{
			BitmapWriter bitmapWriter;
			StringWriter stringWriter;
			MidiWriter midiWriter;

			About about = new About ();
			XmlReader jobReader;

			GeneratedFiles generatedFiles;

			if (about.ParseCmd (args) != true) {
				return 64;
			}

			about.WelcomeBanner ();

			if (Common.jobFile == "") {
				Common.WriteMessage (Common.VerbosityLevel.Error, "No job file");
				Common.WriteMessage (Common.VerbosityLevel.Error, "Try `rca --help' for more information.");

				return 65;
			}

			jobReader = new XmlReader ();

			if ((jobReader.Read (Common.jobFile)) != XmlReadStatus.Success) {
				return 66;
			}

			Common.language = jobReader.rcFile.language;

			generatedFiles = OpenGeneratedFile (jobReader.rcFile.filename);

			// Generate images
			bitmapWriter = new BitmapWriter (generatedFiles);
			if (bitmapWriter.Convert (jobReader.rcImage) != true)
				return 66;

			// Generate texts
			stringWriter = new StringWriter (generatedFiles);
			if (stringWriter.Convert (jobReader.rcString) != true)
				return 66;

			// Generate wavetable
			midiWriter = new MidiWriter (generatedFiles);
			// Generate wavetable
			if (midiWriter.Convert (jobReader.rcWavetable) != true)
				return 66;
			
			// Generate instrument
			if (midiWriter.Convert (jobReader.rcInstrument) != true)
				return 66;
			
			// Generate melody
			if (midiWriter.Convert (jobReader.rcMelody) != true)
				return 66;
			
			CloseGeneratedFile (generatedFiles);

			return 0;
		}

		private static GeneratedFiles OpenGeneratedFile(string filename)
		{
			GeneratedFiles gf;

			gf.filenameshort = Path.GetFileNameWithoutExtension (filename);

			if (Common.language == Common.Languages.C) {
				gf.body = new StreamWriter(gf.filenameshort + ".c");
				gf.spec = new StreamWriter(gf.filenameshort + ".h");

				gf.body.WriteLine ("///"+ Environment.NewLine+"/// Generated by rca " + System.DateTime.Now.ToString () + Environment.NewLine + "///" + Environment.NewLine);
				gf.body.WriteLine("#include \"rc.h\""+ Environment.NewLine);

				gf.spec.WriteLine ("///" + Environment.NewLine +"/// Generated by rca " + System.DateTime.Now.ToString () + Environment.NewLine + "///" + Environment.NewLine);
				gf.spec.WriteLine("#include \"rc.h\""+ Environment.NewLine);
			} else {
				gf.body = null;
				gf.spec = new StreamWriter(gf.filenameshort + ".ads");

				gf.spec.WriteLine ("-- "+ Environment.NewLine +"-- Generated by rca " + System.DateTime.Now.ToString () + Environment.NewLine + "--" + Environment.NewLine);
				gf.spec.WriteLine("pragma Ada_95;"+ Environment.NewLine);
				gf.spec.WriteLine("with Insa;");
				gf.spec.WriteLine("with Insa.Graphics;");
				gf.spec.WriteLine("with Insa.Graphics.Images;");
				gf.spec.WriteLine("with Insa.Audio;");
				gf.spec.WriteLine("with Insa.Audio.Synthesizer;"+ Environment.NewLine);

				gf.spec.WriteLine("use Insa.Graphics.Images;");
				gf.spec.WriteLine("use Insa.Audio.Synthesizer;"+ Environment.NewLine);

				gf.spec.WriteLine("package "+ gf.filenameshort + " is"+ Environment.NewLine);
				gf.spec.WriteLine("    pragma Warnings (Off);"+ Environment.NewLine);
			}

			return gf;
		}

		private static bool CloseGeneratedFile(GeneratedFiles gf)
		{
			if (Common.language == Common.Languages.C) {

				if (gf.body != null)
					gf.body.Close ();

				if (gf.spec != null)
					gf.spec.Close ();
			}
			else {
				if (gf.body != null)
					gf.body.Close ();

				if (gf.spec != null) {
					gf.spec.WriteLine("end " + gf.filenameshort + ";"+ Environment.NewLine);

					gf.spec.Close ();
				}
			}

			return true;
		}
	}
}


