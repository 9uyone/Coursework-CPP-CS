using System;
using System.Collections.Generic;
using System.Windows.Forms;

namespace Coursework_WinForms {
	static class glob {
		static internal fm_main main { get; set; }
		//static internal Dictionary<string, Shape> shapes = new Dictionary<string, Shape>();
		static internal SimpleDictionary<string, Shape> shapes = new SimpleDictionary<string, Shape>();
	}

	public static class Program {
		/// <summary>
		/// The main entry point for the application.
		/// </summary>
		[STAThread]
		static void Main() {
			Application.EnableVisualStyles();
			Application.SetCompatibleTextRenderingDefault(false);
			glob.main = new fm_main();
			Application.Run(glob.main);
		}
	}
}
