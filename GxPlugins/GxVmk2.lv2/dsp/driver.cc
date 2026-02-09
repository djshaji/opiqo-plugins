// generated from file './/driver.dsp' by dsp2cc:
// Code generated with Faust 0.9.73 (http://faust.grame.fr)


namespace driver {

class Dsp: public PluginLV2 {
private:
	uint32_t fSamplingFreq;
	int 	iConst0;
	double 	fConst1;
	double 	fConst2;
	double 	fConst3;
	double 	fConst4;
	double 	fConst5;
	double 	fConst6;
	double 	fConst7;
	double 	fConst8;
	double 	fConst9;
	double 	fConst10;
	double 	fConst11;
	double 	fConst12;
	double 	fConst13;
	double 	fConst14;
	double 	fConst15;
	double 	fConst16;
	double 	fConst17;
	double 	fConst18;
	double 	fConst19;
	double 	fConst20;
	double 	fConst21;
	double 	fConst22;
	double 	fConst23;
	double 	fConst24;
	double 	fConst25;
	double 	fConst26;
	double 	fConst27;
	double 	fRec3[4];
	double 	fConst28;
	double 	fConst29;
	double 	fConst30;
	double 	fConst31;
	double 	fConst32;
	double 	fConst33;
	double 	fConst34;
	double 	fRec2[3];
	double 	fRec1[3];
	double 	fConst35;
	double 	fConst36;
	double 	fConst37;
	double 	fRec0[3];
	double 	fConst38;
	void connect(uint32_t port,void* data);
	void clear_state_f();
	void init(uint32_t samplingFreq);
	void compute(int count, FAUSTFLOAT *input0, FAUSTFLOAT *output0);

	static void clear_state_f_static(PluginLV2*);
	static void init_static(uint32_t samplingFreq, PluginLV2*);
	static void compute_static(int count, FAUSTFLOAT *input0, FAUSTFLOAT *output0, PluginLV2*);
	static void del_instance(PluginLV2 *p);
	static void connect_static(uint32_t port,void* data, PluginLV2 *p);
public:
	Dsp();
	~Dsp();
};



Dsp::Dsp()
	: PluginLV2() {
	version = PLUGINLV2_VERSION;
	id = "driver";
	name = N_("MK2Driver");
	mono_audio = compute_static;
	stereo_audio = 0;
	set_samplerate = init_static;
	activate_plugin = 0;
	connect_ports = connect_static;
	clear_state = clear_state_f_static;
	delete_instance = del_instance;
}

Dsp::~Dsp() {
}

inline void Dsp::clear_state_f()
{
	for (int i=0; i<4; i++) fRec3[i] = 0;
	for (int i=0; i<3; i++) fRec2[i] = 0;
	for (int i=0; i<3; i++) fRec1[i] = 0;
	for (int i=0; i<3; i++) fRec0[i] = 0;
}

void Dsp::clear_state_f_static(PluginLV2 *p)
{
	static_cast<Dsp*>(p)->clear_state_f();
}

inline void Dsp::init(uint32_t samplingFreq)
{
	fSamplingFreq = samplingFreq;
	iConst0 = min(192000, max(1, fSamplingFreq));
	fConst1 = tan((376.99111843077515 / double(iConst0)));
	fConst2 = (1.0 / faustpower<2>(fConst1));
	fConst3 = (2 * (1 - fConst2));
	fConst4 = (1.0 / fConst1);
	fConst5 = (1 + ((fConst4 - 1.414213562373095) / fConst1));
	fConst6 = (1.0 / (1 + ((1.414213562373095 + fConst4) / fConst1)));
	fConst7 = tan((1256.6370614359173 / double(iConst0)));
	fConst8 = (2 * (1 - (1.0 / faustpower<2>(fConst7))));
	fConst9 = double((1.0 / double(iConst0)));
	fConst10 = (fConst9 / sin((2513.2741228718346 * fConst9)));
	fConst11 = (7066.589504111799 * fConst10);
	fConst12 = (1.0 / fConst7);
	fConst13 = (1 + ((fConst12 - fConst11) / fConst7));
	fConst14 = (1.0 / (1 + ((fConst11 + fConst12) / fConst7)));
	fConst15 = tan((17278.75959474386 / double(iConst0)));
	fConst16 = (2 * (1 - (1.0 / faustpower<2>(fConst15))));
	fConst17 = (1.0 / fConst15);
	fConst18 = (1 + ((fConst17 - 1.414213562373095) / fConst15));
	fConst19 = (1.0 / (1 + ((1.414213562373095 + fConst17) / fConst15)));
	fConst20 = double(iConst0);
	fConst21 = (9.03791617470279e-15 * fConst20);
	fConst22 = (1.59962462431754e-12 + (fConst20 * ((fConst20 * (2.07776698204537e-13 - fConst21)) - 1.18527096234434e-12)));
	fConst23 = (2.71137485241084e-14 * fConst20);
	fConst24 = (4.79887387295262e-12 + (fConst20 * ((fConst20 * (fConst23 - 2.07776698204537e-13)) - 1.18527096234434e-12)));
	fConst25 = (4.79887387295262e-12 + (fConst20 * (1.18527096234434e-12 + (fConst20 * (0 - (2.07776698204537e-13 + fConst23))))));
	fConst26 = (1.59962462431754e-12 + (fConst20 * (1.18527096234434e-12 + (fConst20 * (2.07776698204537e-13 + fConst21)))));
	fConst27 = (1.0 / fConst26);
	fConst28 = (3.44311187407419e-13 * fConst20);
	fConst29 = ((fConst20 * (2.16776440355014e-12 - fConst28)) - 1.66185299357055e-13);
	fConst30 = (1.03293356222226e-12 * fConst20);
	fConst31 = ((fConst20 * (fConst30 - 2.16776440355014e-12)) - 1.66185299357055e-13);
	fConst32 = (1.66185299357055e-13 + (fConst20 * (0 - (2.16776440355014e-12 + fConst30))));
	fConst33 = (1.66185299357055e-13 + (fConst20 * (2.16776440355014e-12 + fConst28)));
	fConst34 = (fConst20 / fConst26);
	fConst35 = (1256.6370614359173 * fConst10);
	fConst36 = (1 + ((fConst12 - fConst35) / fConst7));
	fConst37 = (1 + ((fConst35 + fConst12) / fConst7));
	fConst38 = (2 * (0 - fConst2));
	clear_state_f();
}

void Dsp::init_static(uint32_t samplingFreq, PluginLV2 *p)
{
	static_cast<Dsp*>(p)->init(samplingFreq);
}

void always_inline Dsp::compute(int count, FAUSTFLOAT *input0, FAUSTFLOAT *output0)
{
	for (int i=0; i<count; i++) {
		double fTemp0 = (fConst8 * fRec1[1]);
		fRec3[0] = ((double)input0[i] - (fConst27 * (((fConst25 * fRec3[1]) + (fConst24 * fRec3[2])) + (fConst22 * fRec3[3]))));
		fRec2[0] = ((fConst34 * ((((fConst33 * fRec3[0]) + (fConst32 * fRec3[1])) + (fConst31 * fRec3[2])) + (fConst29 * fRec3[3]))) - (fConst19 * ((fConst18 * fRec2[2]) + (fConst16 * fRec2[1]))));
		fRec1[0] = ((fConst19 * (fRec2[2] + (fRec2[0] + (2 * fRec2[1])))) - (fConst14 * ((fConst13 * fRec1[2]) + fTemp0)));
		fRec0[0] = ((fConst14 * ((fTemp0 + (fConst37 * fRec1[0])) + (fConst36 * fRec1[2]))) - (fConst6 * ((fConst5 * fRec0[2]) + (fConst3 * fRec0[1]))));
		output0[i] = (FAUSTFLOAT)(fConst6 * (((fConst2 * fRec0[0]) + (fConst38 * fRec0[1])) + (fConst2 * fRec0[2])));
		// post processing
		fRec0[2] = fRec0[1]; fRec0[1] = fRec0[0];
		fRec1[2] = fRec1[1]; fRec1[1] = fRec1[0];
		fRec2[2] = fRec2[1]; fRec2[1] = fRec2[0];
		for (int i=3; i>0; i--) fRec3[i] = fRec3[i-1];
	}
}

void __rt_func Dsp::compute_static(int count, FAUSTFLOAT *input0, FAUSTFLOAT *output0, PluginLV2 *p)
{
	static_cast<Dsp*>(p)->compute(count, input0, output0);
}


void Dsp::connect(uint32_t port,void* data)
{
	switch ((PortIndex)port)
	{
	default:
		break;
	}
}

void Dsp::connect_static(uint32_t port,void* data, PluginLV2 *p)
{
	static_cast<Dsp*>(p)->connect(port, data);
}


PluginLV2 *plugin() {
	return new Dsp();
}

void Dsp::del_instance(PluginLV2 *p)
{
	delete static_cast<Dsp*>(p);
}

/*
typedef enum
{
} PortIndex;
*/

} // end namespace driver
