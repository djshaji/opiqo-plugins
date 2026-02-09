// generated from file './/viberev.dsp' by dsp2cc:
// Code generated with Faust 0.9.73 (http://faust.grame.fr)


namespace viberev {

class Dsp: public PluginLV2 {
private:
	uint32_t fSamplingFreq;
	int 	iVec0[2];
	FAUSTFLOAT 	fslider0;
	FAUSTFLOAT	*fslider0_;
	int 	iConst0;
	double 	fConst1;
	double 	fRec2[2];
	double 	fRec1[2];
	double 	fRec0[2];
	FAUSTFLOAT 	fslider1;
	FAUSTFLOAT	*fslider1_;
	double 	fConst2;
	double 	fConst3;
	double 	fConst4;
	double 	fConst5;
	double 	fConst6;
	FAUSTFLOAT 	fslider2;
	FAUSTFLOAT	*fslider2_;
	int 	IOTA;
	double 	fVec1[512];
	double 	fRec11[2];
	double 	fVec2[128];
	double 	fRec9[2];
	double 	fVec3[64];
	double 	fRec7[2];
	double 	fVec4[4096];
	double 	fRec5[2];
	double 	fRec6[2];
	double 	fVec5[4096];
	double 	fRec13[2];
	double 	fRec14[2];
	double 	fVec6[2048];
	double 	fRec15[2];
	double 	fRec16[2];
	double 	fVec7[2048];
	double 	fRec17[2];
	double 	fRec18[2];
	double 	fVec8[2];
	double 	fConst7;
	double 	fConst8;
	double 	fConst9;
	double 	fRec4[2];
	double 	fRec3[3];
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
	id = "mk2d";
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
	for (int i=0; i<2; i++) iVec0[i] = 0;
	for (int i=0; i<2; i++) fRec2[i] = 0;
	for (int i=0; i<2; i++) fRec1[i] = 0;
	for (int i=0; i<2; i++) fRec0[i] = 0;
	for (int i=0; i<512; i++) fVec1[i] = 0;
	for (int i=0; i<2; i++) fRec11[i] = 0;
	for (int i=0; i<128; i++) fVec2[i] = 0;
	for (int i=0; i<2; i++) fRec9[i] = 0;
	for (int i=0; i<64; i++) fVec3[i] = 0;
	for (int i=0; i<2; i++) fRec7[i] = 0;
	for (int i=0; i<4096; i++) fVec4[i] = 0;
	for (int i=0; i<2; i++) fRec5[i] = 0;
	for (int i=0; i<2; i++) fRec6[i] = 0;
	for (int i=0; i<4096; i++) fVec5[i] = 0;
	for (int i=0; i<2; i++) fRec13[i] = 0;
	for (int i=0; i<2; i++) fRec14[i] = 0;
	for (int i=0; i<2048; i++) fVec6[i] = 0;
	for (int i=0; i<2; i++) fRec15[i] = 0;
	for (int i=0; i<2; i++) fRec16[i] = 0;
	for (int i=0; i<2048; i++) fVec7[i] = 0;
	for (int i=0; i<2; i++) fRec17[i] = 0;
	for (int i=0; i<2; i++) fRec18[i] = 0;
	for (int i=0; i<2; i++) fVec8[i] = 0;
	for (int i=0; i<2; i++) fRec4[i] = 0;
	for (int i=0; i<3; i++) fRec3[i] = 0;
}

void Dsp::clear_state_f_static(PluginLV2 *p)
{
	static_cast<Dsp*>(p)->clear_state_f();
}

inline void Dsp::init(uint32_t samplingFreq)
{
	fSamplingFreq = samplingFreq;
	iConst0 = min(192000, max(1, fSamplingFreq));
	fConst1 = (62.83185307179586 / double(iConst0));
	fConst2 = tan((20461.192952830323 / double(iConst0)));
	fConst3 = (2 * (1 - (1.0 / faustpower<2>(fConst2))));
	fConst4 = (1.0 / fConst2);
	fConst5 = (1 + ((fConst4 - 1.0000000000000004) / fConst2));
	fConst6 = (1.0 / (1 + ((1.0000000000000004 + fConst4) / fConst2)));
	IOTA = 0;
	fConst7 = (1 + fConst4);
	fConst8 = (2.0 / fConst7);
	fConst9 = (0 - ((1 - fConst4) / fConst7));
	clear_state_f();
}

void Dsp::init_static(uint32_t samplingFreq, PluginLV2 *p)
{
	static_cast<Dsp*>(p)->init(samplingFreq);
}

void always_inline Dsp::compute(int count, FAUSTFLOAT *input0, FAUSTFLOAT *output0)
{
#define fslider0 (*fslider0_)
#define fslider1 (*fslider1_)
#define fslider2 (*fslider2_)
	double 	fSlow0 = (fConst1 * double(fslider0));
	double 	fSlow1 = double(fslider1);
	double 	fSlow2 = (0.06 * double(fslider2));
	for (int i=0; i<count; i++) {
		iVec0[0] = 1;
		fRec2[0] = (fRec2[1] + (fSlow0 * (0 - fRec0[1])));
		fRec1[0] = ((1 + (fRec1[1] + (fSlow0 * fRec2[0]))) - iVec0[1]);
		fRec0[0] = fRec1[0];
		double fTemp0 = (double)input0[i];
		double fTemp1 = ((0.7 * fRec11[1]) + (fSlow2 * fTemp0));
		fVec1[IOTA&511] = fTemp1;
		fRec11[0] = fVec1[(IOTA-346)&511];
		double 	fRec12 = (0 - (0.7 * fVec1[IOTA&511]));
		double fTemp2 = (fRec11[1] + (fRec12 + (0.7 * fRec9[1])));
		fVec2[IOTA&127] = fTemp2;
		fRec9[0] = fVec2[(IOTA-112)&127];
		double 	fRec10 = (0 - (0.7 * fVec2[IOTA&127]));
		double fTemp3 = (fRec9[1] + (fRec10 + (0.7 * fRec7[1])));
		fVec3[IOTA&63] = fTemp3;
		fRec7[0] = fVec3[(IOTA-36)&63];
		double 	fRec8 = (0 - (0.7 * fVec3[IOTA&63]));
		double fTemp4 = (fRec8 + fRec7[1]);
		double fTemp5 = (fTemp4 + (0.733 * fRec5[1]));
		fVec4[IOTA&4095] = fTemp5;
		fRec5[0] = fVec4[(IOTA-2250)&4095];
		fRec6[0] = fVec4[IOTA&4095];
		double fTemp6 = (fTemp4 + (0.753 * fRec13[1]));
		fVec5[IOTA&4095] = fTemp6;
		fRec13[0] = fVec5[(IOTA-2052)&4095];
		fRec14[0] = fVec5[IOTA&4095];
		double fTemp7 = (fTemp4 + (0.773 * fRec15[1]));
		fVec6[IOTA&2047] = fTemp7;
		fRec15[0] = fVec6[(IOTA-1866)&2047];
		fRec16[0] = fVec6[IOTA&2047];
		double fTemp8 = (fRec7[1] + (fRec8 + (0.802 * fRec17[1])));
		fVec7[IOTA&2047] = fTemp8;
		fRec17[0] = fVec7[(IOTA-1600)&2047];
		fRec18[0] = fVec7[IOTA&2047];
		double fTemp9 = (((fRec18[1] + fRec16[1]) + fRec14[1]) + fRec6[1]);
		double fTemp10 = (fTemp9 + fTemp9);
		fVec8[0] = fTemp10;
		fRec4[0] = ((fConst9 * fRec4[1]) + (fConst8 * (fVec8[0] + fVec8[1])));
		fRec3[0] = (fRec4[0] - (fConst6 * ((fConst5 * fRec3[2]) + (fConst3 * fRec3[1]))));
		output0[i] = (FAUSTFLOAT)((fConst6 * (fRec3[2] + (fRec3[0] + (2 * fRec3[1])))) + (fTemp0 * (1 + (1 + (fSlow1 * (max((double)0, (0.5 * (1 + fRec0[0]))) - 1))))));
		// post processing
		fRec3[2] = fRec3[1]; fRec3[1] = fRec3[0];
		fRec4[1] = fRec4[0];
		fVec8[1] = fVec8[0];
		fRec18[1] = fRec18[0];
		fRec17[1] = fRec17[0];
		fRec16[1] = fRec16[0];
		fRec15[1] = fRec15[0];
		fRec14[1] = fRec14[0];
		fRec13[1] = fRec13[0];
		fRec6[1] = fRec6[0];
		fRec5[1] = fRec5[0];
		fRec7[1] = fRec7[0];
		fRec9[1] = fRec9[0];
		fRec11[1] = fRec11[0];
		IOTA = IOTA+1;
		fRec0[1] = fRec0[0];
		fRec1[1] = fRec1[0];
		fRec2[1] = fRec2[0];
		iVec0[1] = iVec0[0];
	}
#undef fslider0
#undef fslider1
#undef fslider2
}

void __rt_func Dsp::compute_static(int count, FAUSTFLOAT *input0, FAUSTFLOAT *output0, PluginLV2 *p)
{
	static_cast<Dsp*>(p)->compute(count, input0, output0);
}


void Dsp::connect(uint32_t port,void* data)
{
	switch ((PortIndex)port)
	{
	case DEPTH: 
		fslider1_ = (float*)data; // , 0.5, 0.0, 1.0, 0.01 
		break;
	case REVERBLEVEL: 
		fslider2_ = (float*)data; // , 0.5, 0.0, 1.0, 0.01 
		break;
	case SPEED: 
		fslider0_ = (float*)data; // , 0.5, 0.01, 1.0, 0.01 
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
   DEPTH, 
   REVERBLEVEL, 
   SPEED, 
} PortIndex;
*/

} // end namespace viberev
