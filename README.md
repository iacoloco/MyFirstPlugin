🎛️ MyFirstPlugin – VCV Rack DSP Module

MyFirstPlugin is a beginner-friendly VCV Rack plugin created entirely from scratch by Armando Iachini as a stepping stone into the world of audio DSP and real-time C++ programming.

This project serves as a foundational step toward a professional DSP development career, focusing on C++ OOP, digital signal processing, and custom GUI design.

⸻

📚 Learning Objectives

This plugin was developed as a self-study project to learn:
	•	🎧 Real-time audio processing with the VCV Rack SDK
	•	🧠 Core DSP concepts: phase, frequency, and waveform generation
	•	🧱 C++ classes, pointers, and object-oriented architecture
	•	🎨 GUI design using SVG and Inkscape
	•	🔧 Build automation using Makefiles
	•	🧬 Git version control and open-source workflows

⸻

🛠️ Built With
	•	VCV Rack SDK v2
	•	C++ (Modern, modular, object-oriented)
	•	Inkscape (SVG GUI design)
	•	macOS Terminal + Make
	•	Git & GitHub

⸻

✅ First Feature: Custom Sine Oscillator

My first module is a sine wave oscillator, which generates a clean periodic waveform using phase accumulation and trigonometric synthesis. It features:
	•	A pitch knob and CV input to control frequency
	•	Real-time phase accumulation per sample
	•	A custom SVG interface panel
	•	Blinking indicator LED to verify module activity
	•	Basic waveform experimentation by combining multiple sine waves at different frequencies

This module helped me understand fundamental DSP principles, including phase wrapping, sample timing, and waveform amplitude management.

⸻

📈 What’s Next

This is just the beginning! I’m currently building a series of additional modules, including:
	•	Envelope Generator
	•	Filter (SVF)
	•	VCA
	•	Delay & Reverb
	•	Compressor & Waveshaper

Along the way, I’ll be diving deeper into DSP topics like:
	•	Anti-aliasing (e.g., polyBLEP)
	•	Oversampling
	•	Filter design
	•	Modulation (AM, FM, RM)
	•	Normalization and gain staging