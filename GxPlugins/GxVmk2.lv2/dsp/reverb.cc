// generated from file './/reverb.dsp' by dsp2cc:
// Code generated with Faust 0.9.73 (http://faust.grame.fr)


namespace reverb {

class Dsp: public PluginLV2 {
private:
	uint32_t fSamplingFreq;
	double 	fConst0;
	double 	fConst1;
	double 	fConst2;
	double 	fConst3;
	double 	fConst4;
	FAUSTFLOAT 	fslider0;
	FAUSTFLOAT	*fslider0_;
	int 	IOTA;
	double 	fVec0[512];
	double 	fRec8[2];
	double 	fVec1[128];
	double 	fRec6[2];
	double 	fVec2[64];
	double 	fRec4[2];
	double 	fVec3[4096];
	double 	fRec2[2];
	double 	fRec3[2];
	double 	fVec4[4096];
	double 	fRec10[2];
	double 	fRec11[2];
	double 	fVec5[2048];
	double 	fRec12[2];
	double 	fRec13[2];
	double 	fVec6[2048];
	double 	fRec14[2];
	double 	fRec15[2];
	double 	fVec7[2];
	double 	fConst5;
	double 	fConst6;
	double 	fConst7;
	double 	fRec1[2];
	double 	fRec0[3];
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
	id = "reverb";
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
	for (int i=0; i<512; i++) fVec0[i] = 0;
	for (int i=0; i<2; i++) fRec8[i] = 0;
	for (int i=0; i<128; i++) fVec1[i] = 0;
	for (int i=0; i<2; i++) fRec6[i] = 0;
	for (int i=0; i<64; i++) fVec2[i] = 0;
	for (int i=0; i<2; i++) fRec4[i] = 0;
	for (int i=0; i<4096; i++) fVec3[i] = 0;
	for (int i=0; i<2; i++) fRec2[i] = 0;
	for (int i=0; i<2; i++) fRec3[i] = 0;
	for (int i=0; i<4096; i++) fVec4[i] = 0;
	for (int i=0; i<2; i++) fRec10[i] = 0;
	for (int i=0; i<2; i++) fRec11[i] = 0;
	for (int i=0; i<2048; i++) fVec5[i] = 0;
	for (int i=0; i<2; i++) fRec12[i] = 0;
	for (int i=0; i<2; i++) fRec13[i] = 0;
	for (int i=0; i<2048; i++) fVec6[i] = 0;
	for (int i=0; i<2; i++) fRec14[i] = 0;
	for (int i=0; i<2; i++) fRec15[i] = 0;
	for (int i=0; i<2; i++) fVec7[i] = 0;
	for (int i=0; i<2; i++) fRec1[i] = 0;
	for (int i=0; i<3; i++) fRec0[i] = 0;
}

void Dsp::clear_state_f_static(PluginLV2 *p)
{
	static_cast<Dsp*>(p)->clear_state_f();
}

inline void Dsp::init(uint32_t samplingFreq)
{
	fSamplingFreq = samplingFreq;
	fConst0 = tan((20461.192952830323 / double(min(192000, max(1, fSamplingFreq)))));
	fConst1 = (2 * (1 - (1.0 / faustpower<2>(fConst0))));
	fConst2 = (1.0 / fConst0);
	fConst3 = (1 + ((fConst2 - 1.0000000000000004) / fConst0));
	fConst4 = (1.0 / (1 + ((1.0000000000000004 + fConst2) / fConst0)));
	IOTA = 0;
	fConst5 = (1 + fConst2);
	fConst6 = (2.0 / fConst5);
	fConst7 = (0 - ((1 - fConst2) / fConst5));
	clear_state_f();
}

void Dsp::init_static(uint32_t samplingFreq, PluginLV2 *p)
{
	static_cast<Dsp*>(p)->init(samplingFreq);
}

void always_inline Dsp::compute(int count, FAUSTFLOAT *input0, FAUSTFLOAT *output0)
{
#define fslider0 (*fslider0_)
	double 	fSlow0 = (0.06 * double(fslider0));
	for (int i=0; i<count; i++) {
		double fTemp0 = (double)input0[i];
		double fTemp1 = ((0.7 * fRec8[1]) + (fSlow0 * fTemp0));
		fVec0[IOTA&511] = fTemp1;
		fRec8[0] = fVec0[(IOTA-346)&511];
		double 	fRec9 = (0 - (0.7 * fVec0[IOTA&511]));
		double fTemp2 = (fRec8[1] + (fRec9 + (0.7 * fRec6[1])));
		fVec1[IOTA&127] = fTemp2;
		fRec6[0] = fVec1[(IOTA-112)&127];
		double 	fRec7 = (0 - (0.7 * fVec1[IOTA&127]));
		double fTemp3 = (fRec6[1] + (fRec7 + (0.7 * fRec4[1])));
		fVec2[IOTA&63] = fTemp3;
		fRec4[0] = fVec2[(IOTA-36)&63];
		double 	fRec5 = (0 - (0.7 * fVec2[IOTA&63]));
		double fTemp4 = (fRec5 + fRec4[1]);
		double fTemp5 = (fTemp4 + (0.733 * fRec2[1]));
		fVec3[IOTA&4095] = fTemp5;
		fRec2[0] = fVec3[(IOTA-2250)&4095];
		fRec3[0] = fVec3[IOTA&4095];
		double fTemp6 = (fTemp4 + (0.753 * fRec10[1]));
		fVec4[IOTA&4095] = fTemp6;
		fRec10[0] = fVec4[(IOTA-2052)&4095];
		fRec11[0] = fVec4[IOTA&4095];
		double fTemp7 = (fTemp4 + (0.773 * fRec12[1]));
		fVec5[IOTA&2047] = fTemp7;
		fRec12[0] = fVec5[(IOTA-1866)&2047];
		fRec13[0] = fVec5[IOTA&2047];
		double fTemp8 = (fRec4[1] + (fRec5 + (0.802 * fRec14[1])));
		fVec6[IOTA&2047] = fTemp8;
		fRec14[0] = fVec6[(IOTA-1600)&2047];
		fRec15[0] = fVec6[IOTA&2047];
		double fTemp9 = (((fRec15[1] + fRec13[1]) + fRec11[1]) + fRec3[1]);
		double fTemp10 = (fTemp9 + fTemp9);
		fVec7[0] = fTemp10;
		fRec1[0] = ((fConst7 * fRec1[1]) + (fConst6 * (fVec7[0] + fVec7[1])));
		fRec0[0] = (fRec1[0] - (fConst4 * ((fConst3 * fRec0[2]) + (fConst1 * fRec0[1]))));
		output0[i] = (FAUSTFLOAT)(fTemp0 + (fConst4 * (fRec0[2] + (fRec0[0] + (2 * fRec0[1])))));
		// post processing
		fRec0[2] = fRec0[1]; fRec0[1] = fRec0[0];
		fRec1[1] = fRec1[0];
		fVec7[1] = fVec7[0];
		fRec15[1] = fRec15[0];
		fRec14[1] = fRec14[0];
		fRec13[1] = fRec13[0];
		fRec12[1] = fRec12[0];
		fRec11[1] = fRec11[0];
		fRec10[1] = fRec10[0];
		fRec3[1] = fRec3[0];
		fRec2[1] = fRec2[0];
		fRec4[1] = fRec4[0];
		fRec6[1] = fRec6[0];
		fRec8[1] = fRec8[0];
		IOTA = IOTA+1;
	}
#undef fslider0
}

void __rt_func Dsp::compute_static(int count, FAUSTFLOAT *input0, FAUSTFLOAT *output0, PluginLV2 *p)
{
	static_cast<Dsp*>(p)->compute(count, input0, output0);
}


void Dsp::connect(uint32_t port,void* data)
{
	switch ((PortIndex)port)
	{
	case REVERBLEVEL: 
		fslider0_ = (float*)data; // , 0.5, 0.0, 1.0, 0.01 
		break;
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
   REVERBLEVEL, 
} PortIndex;
*/

} // end namespace reverb
