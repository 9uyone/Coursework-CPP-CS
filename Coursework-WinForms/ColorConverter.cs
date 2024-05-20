using System;
using System.Drawing;
using System.Text.Json;
using System.Text.Json.Serialization;

namespace Coursework_WinForms {
	public class ColorConverter : JsonConverter<Color> {
		public override Color Read(ref Utf8JsonReader reader, Type typeToConvert, JsonSerializerOptions options) {
			string colorHex = reader.GetString();
			return ColorTranslator.FromHtml(colorHex);
		}

		public override void Write(Utf8JsonWriter writer, Color value, JsonSerializerOptions options) {
			string colorHex = ColorTranslator.ToHtml(value);
			writer.WriteStringValue(colorHex);
		}

		public static Color IdealTextColor(Color bg) {
			int nThreshold = 105;
			int bgDelta = Convert.ToInt32((bg.R * 0.299) + (bg.G * 0.587) + (bg.B * 0.114));
			Color foreColor = (255 - bgDelta < nThreshold) ? Color.Black : Color.White;
			return foreColor;
		}
	}
}