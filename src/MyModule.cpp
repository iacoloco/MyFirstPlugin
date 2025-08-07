#include "plugin.hpp"


struct MyOsc : Module {
    float phase = 0.f;
    float blinkPhase = 0.f;
    
	enum ParamId {
		PITCH_PARAM,
		PARAMS_LEN
	};
	enum InputId {
		PITCH_INPUT,
		INPUTS_LEN
	};
	enum OutputId {
		SINE_OUTPUT,
		OUTPUTS_LEN
	};
	enum LightId {
		BLINK_LIGHT,
		LIGHTS_LEN
	};

	MyOsc() {
		config(PARAMS_LEN, INPUTS_LEN, OUTPUTS_LEN, LIGHTS_LEN);
		configParam(PITCH_PARAM, 0.f, 1.f, 0.f, "");
		configInput(PITCH_INPUT, "");
		configOutput(SINE_OUTPUT, "");
	}

    // THE ACTUAL DSP CODE!!!!!!!!!!!!!!!!!!!!



    //This function run 48000 times x second meaning each sample is taken at 0.0000208 seconds (1/48000) 
    void process(const ProcessArgs &args) override {
        // Compute the frequency from the pitch parameter and input
        float pitch = params[PITCH_PARAM].getValue();
        pitch += inputs[PITCH_INPUT].getVoltage();
        // The default frequency is C4 = 261.6256 Hz
        float freq = dsp::FREQ_C4 * std::pow(2.f, pitch);
		

        // Accumulate the phase
        phase += freq * args.sampleTime;
        if (phase >= 1.f)
            phase -= 1.f;

        // Compute the sine output
        //float sine = std::sin(2.f * M_PI * phase) + 0.5f * std::sin(2.f * M_PI * (2*phase)) + 0.25 * std::sin(2.f * M_PI * (3*phase)); 
		// sin max = 1 + 0.5 + 0.25 = 1.75
		// volt max = 1.75 * 5 = 8.75.
		// outputs[SINE_OUTPUT].setVoltage((5.f * sine)/1.75f);

		//-----------------------------------------------------

		//Task 2: create a triangle wave.
		//Hint Don't need sin function

		float triangleWave = 4.f * std::abs(phase - 0.5f) - 1.f;
		outputs[SINE_OUTPUT].setVoltage(5.f * triangleWave);



        // Blink light at 1Hz
        blinkPhase += args.sampleTime;
        if (blinkPhase >= 1.f)
            blinkPhase -= 1.f;
        lights[BLINK_LIGHT].setBrightness(blinkPhase < 0.5f ? 1.f : 0.f);
    }

};

//GUI

struct MyModuleWidget : ModuleWidget {
	MyModuleWidget(MyOsc* module) {
		setModule(module);
		setPanel(createPanel(asset::plugin(pluginInstance, "res/MyOsc.svg")));

		addChild(createWidget<ScrewSilver>(Vec(RACK_GRID_WIDTH, 0)));
		addChild(createWidget<ScrewSilver>(Vec(box.size.x - 2 * RACK_GRID_WIDTH, 0)));
		addChild(createWidget<ScrewSilver>(Vec(RACK_GRID_WIDTH, RACK_GRID_HEIGHT - RACK_GRID_WIDTH)));
		addChild(createWidget<ScrewSilver>(Vec(box.size.x - 2 * RACK_GRID_WIDTH, RACK_GRID_HEIGHT - RACK_GRID_WIDTH)));

		addChild(createLightCentered<MediumLight<RedLight>>(mm2px(Vec(24.600, 11.500)), module, MyOsc::BLINK_LIGHT));

		addParam(createParamCentered<SynthTechAlco>(mm2px(Vec(25.00,  41.257)), module, MyOsc::PITCH_PARAM));

		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(25.00, 81.976)), module, MyOsc::PITCH_INPUT));

		addOutput(createOutputCentered<PJ301MPort>(mm2px(Vec(25.00, 100.929)), module, MyOsc::SINE_OUTPUT));

		
	}
};


Model* modelMyOsc = createModel<MyOsc, MyModuleWidget>("MyOsc");
