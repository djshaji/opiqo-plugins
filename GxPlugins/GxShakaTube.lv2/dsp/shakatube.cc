// generated from file './/shakatube.dsp' by dsp2cc:
// Code generated with Faust 0.9.90 (http://faust.grame.fr)

#include "shakatubep2_table.h"

namespace shakatube {

class Dsp: public PluginLV2 {
private:
	uint32_t fSamplingFreq;
	double 	fConst0;
	double 	fConst1;
	double 	fConst2;
	double 	fConst3;
	double 	fConst4;
	double 	fConst5;
	double 	fConst6;
	double 	fConst7;
	FAUSTFLOAT 	fslider0;
	FAUSTFLOAT	*fslider0_;
	double 	fRec1[2];
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
	FAUSTFLOAT 	fslider1;
	FAUSTFLOAT	*fslider1_;
	double 	fRec3[2];
	double 	fConst22;
	double 	fConst23;
	double 	fConst24;
	double 	fConst25;
	double 	fConst26;
	double 	fConst27;
	double 	fConst28;
	double 	fRec4[3];
	double 	fRec2[6];
	double 	fConst29;
	double 	fConst30;
	double 	fConst31;
	double 	fConst32;
	double 	fConst33;
	double 	fConst34;
	double 	fConst35;
	double 	fConst36;
	double 	fConst37;
	double 	fConst38;
	double 	fConst39;
	double 	fConst40;
	double 	fConst41;
	double 	fConst42;
	double 	fConst43;
	double 	fRec0[4];
	FAUSTFLOAT 	fslider2;
	FAUSTFLOAT	*fslider2_;
	double 	fRec5[2];
	double 	fConst44;

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
	id = "shakatube";
	name = N_("shakatube");
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
	for (int i=0; i<2; i++) fRec1[i] = 0;
	for (int i=0; i<2; i++) fRec3[i] = 0;
	for (int i=0; i<3; i++) fRec4[i] = 0;
	for (int i=0; i<6; i++) fRec2[i] = 0;
	for (int i=0; i<4; i++) fRec0[i] = 0;
	for (int i=0; i<2; i++) fRec5[i] = 0;
}

void Dsp::clear_state_f_static(PluginLV2 *p)
{
	static_cast<Dsp*>(p)->clear_state_f();
}

inline void Dsp::init(uint32_t samplingFreq)
{
	fSamplingFreq = samplingFreq;
	fConst0 = double(min(1.92e+05, max(1.0, (double)fSamplingFreq)));
	fConst1 = (3.56096305935309e-15 * fConst0);
	fConst2 = (0.00111021000345228 + (fConst0 * ((fConst0 * (2.32829046680868e-10 - fConst1)) - 1.42995082883024e-06)));
	fConst3 = (1.06828891780593e-14 * fConst0);
	fConst4 = (0.00333063001035685 + (fConst0 * ((fConst0 * (fConst3 - 2.32829046680868e-10)) - 1.42995082883024e-06)));
	fConst5 = (0.00333063001035685 + (fConst0 * (1.42995082883024e-06 + (fConst0 * (0 - (2.32829046680868e-10 + fConst3))))));
	fConst6 = (0.00111021000345228 + (fConst0 * (1.42995082883024e-06 + (fConst0 * (2.32829046680868e-10 + fConst1)))));
	fConst7 = (1.0 / fConst6);
	fConst8 = (8.48689513487333e-24 * fConst0);
	fConst9 = ((fConst0 * ((fConst0 * (3.77235810192933e-22 - fConst8)) - 4.18991067673861e-21)) - 4.55225406704617e-23);
	fConst10 = (4.24344756743666e-21 * fConst0);
	fConst11 = (2.09495533836931e-18 + (fConst0 * (fConst10 - 1.88617905096466e-19)));
	fConst12 = (3.83269488985346e-24 * fConst0);
	fConst13 = (5.91904662625483e-14 + (fConst0 * ((fConst0 * (1.72982027275555e-16 + (fConst0 * ((fConst0 * (4.38026991852912e-21 - fConst12)) - 1.45978173453495e-18)))) - 5.83210236289518e-15)));
	fConst14 = (1.91634744492673e-23 * fConst0);
	fConst15 = (2.95952331312742e-13 + (fConst0 * ((fConst0 * (1.72982027275555e-16 + (fConst0 * (1.45978173453495e-18 + (fConst0 * (fConst14 - 1.31408097555874e-20)))))) - 1.74963070886856e-14)));
	fConst16 = (3.83269488985346e-23 * fConst0);
	fConst17 = (5.91904662625483e-13 + (fConst0 * ((fConst0 * ((fConst0 * (2.9195634690699e-18 + (fConst0 * (8.76053983705825e-21 - fConst16)))) - 3.45964054551111e-16)) - 1.16642047257904e-14)));
	fConst18 = (5.91904662625483e-13 + (fConst0 * (1.16642047257904e-14 + (fConst0 * ((fConst0 * ((fConst0 * (8.76053983705825e-21 + fConst16)) - 2.9195634690699e-18)) - 3.45964054551111e-16)))));
	fConst19 = (2.95952331312742e-13 + (fConst0 * (1.74963070886856e-14 + (fConst0 * (1.72982027275555e-16 + (fConst0 * ((fConst0 * (0 - (1.31408097555874e-20 + fConst14))) - 1.45978173453495e-18)))))));
	fConst20 = (5.91904662625483e-14 + (fConst0 * (5.83210236289518e-15 + (fConst0 * (1.72982027275555e-16 + (fConst0 * (1.45978173453495e-18 + (fConst0 * (4.38026991852912e-21 + fConst12)))))))));
	fConst21 = (1.0 / fConst20);
	fConst22 = (1.92413877615e-12 * fConst0);
	fConst23 = (1.36463742989362e-10 + fConst22);
	fConst24 = (4.23314763858308e-10 * fConst0);
	fConst25 = (4.67330964027386e-07 + fConst24);
	fConst26 = faustpower<2>(fConst0);
	fConst27 = (fConst22 - 1.36463742989362e-10);
	fConst28 = (fConst24 - 4.67330964027386e-07);
	fConst29 = (4.24344756743666e-23 * fConst0);
	fConst30 = ((fConst0 * (4.18991067673861e-21 + (fConst0 * (fConst29 - 1.1317074305788e-21)))) - 4.55225406704617e-23);
	fConst31 = (1.273034270231e-20 * fConst0);
	fConst32 = (2.09495533836931e-18 + (fConst0 * (1.88617905096466e-19 - fConst31)));
	fConst33 = (8.48689513487333e-23 * fConst0);
	fConst34 = (9.10450813409234e-23 + (fConst0 * (8.37982135347722e-21 + (fConst0 * (7.54471620385866e-22 - fConst33)))));
	fConst35 = (8.48689513487333e-21 * fConst0);
	fConst36 = ((fConst0 * (3.77235810192933e-19 + fConst35)) - 4.18991067673861e-18);
	fConst37 = (9.10450813409234e-23 + (fConst0 * ((fConst0 * (7.54471620385866e-22 + fConst33)) - 8.37982135347722e-21)));
	fConst38 = ((fConst0 * (fConst35 - 3.77235810192933e-19)) - 4.18991067673861e-18);
	fConst39 = ((fConst0 * ((fConst0 * (0 - (1.1317074305788e-21 + fConst29))) - 4.18991067673861e-21)) - 4.55225406704617e-23);
	fConst40 = (2.09495533836931e-18 + (fConst0 * (0 - (1.88617905096466e-19 + fConst31))));
	fConst41 = ((fConst0 * (4.18991067673861e-21 + (fConst0 * (3.77235810192933e-22 + fConst8)))) - 4.55225406704617e-23);
	fConst42 = (2.09495533836931e-18 + (fConst0 * (1.88617905096466e-19 + fConst10)));
	fConst43 = (fConst0 / fConst20);
	fConst44 = (fConst0 / fConst6);
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
	double 	fSlow0 = (0.007000000000000006 * double(fslider0));
	double 	fSlow1 = (4.748558434412966e-05 * (exp((5 * double(fslider1))) - 1));
	double 	fSlow2 = (0.007000000000000006 * double(fslider2));
	for (int i=0; i<count; i++) {
		fRec1[0] = (fSlow0 + (0.993 * fRec1[1]));
		fRec3[0] = (fSlow1 + (0.993 * fRec3[1]));
		double fTemp0 = (3.10147971879073e-05 + (fConst0 * (fConst25 + (fConst23 * fRec3[0]))));
		double fTemp1 = (fConst0 * (4.23310530753e-10 + (1.92413877615e-07 * fRec3[0])));
		fRec4[0] = ((double)input0[i] - (((fRec4[2] * (3.10147971879073e-05 + (fConst0 * (fConst28 + (fConst27 * fRec3[0]))))) + (fRec4[1] * (6.20295943758145e-05 + (fConst26 * (0 - (8.46629527716615e-10 + (3.8482775523e-12 * fRec3[0]))))))) / fTemp0));
		fRec2[0] = ((fConst0 * ((((fRec4[0] * (4.37304267306818e-07 + fTemp1)) + (fConst0 * (fRec4[1] * (0 - (8.46621061506e-10 + (3.8482775523e-07 * fRec3[0])))))) + (fRec4[2] * (fTemp1 - 4.37304267306818e-07))) / fTemp0)) - (fConst21 * (((((fConst19 * fRec2[1]) + (fConst18 * fRec2[2])) + (fConst17 * fRec2[3])) + (fConst15 * fRec2[4])) + (fConst13 * fRec2[5]))));
		fRec0[0] = (tubeclip((fConst43 * ((((((fRec2[0] * ((fConst0 * (fConst42 + (fConst41 * fRec1[0]))) - 2.27612703352309e-20)) + (fRec2[1] * ((fConst0 * (fConst40 + (fConst39 * fRec1[0]))) - 6.82838110056925e-20))) + (fRec2[2] * ((fConst0 * (fConst38 + (fConst37 * fRec1[0]))) - 4.55225406704617e-20))) + (fRec2[3] * (4.55225406704617e-20 + (fConst0 * (fConst36 + (fConst34 * fRec1[0])))))) + (fRec2[4] * (6.82838110056925e-20 + (fConst0 * (fConst32 + (fConst30 * fRec1[0])))))) + (fRec2[5] * (2.27612703352309e-20 + (fConst0 * (fConst11 + (fConst9 * fRec1[0])))))))) - (fConst7 * (((fConst5 * fRec0[1]) + (fConst4 * fRec0[2])) + (fConst2 * fRec0[3]))));
		fRec5[0] = (fSlow2 + (0.993 * fRec5[1]));
		output0[i] = (FAUSTFLOAT)(fConst44 * ((1.2212187916096e-06 * (fRec5[0] * (fRec0[1] + fRec0[0]))) + ((0 - (1.2212187916096e-06 * fRec5[0])) * (fRec0[2] + fRec0[3]))));
		// post processing
		fRec5[1] = fRec5[0];
		for (int i=3; i>0; i--) fRec0[i] = fRec0[i-1];
		for (int i=5; i>0; i--) fRec2[i] = fRec2[i-1];
		fRec4[2] = fRec4[1]; fRec4[1] = fRec4[0];
		fRec3[1] = fRec3[0];
		fRec1[1] = fRec1[0];
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
	case DRIVE: 
		fslider1_ = (float*)data; // , 0.5, 0.0, 1.0, 0.01 
		break;
	case TONE: 
		fslider0_ = (float*)data; // , 0.5, 0.0, 1.0, 0.01 
		break;
	case VOLUME: 
		fslider2_ = (float*)data; // , 0.5, 0.0, 1.0, 0.01 
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
   DRIVE, 
   TONE, 
   VOLUME, 
} PortIndex;
*/

} // end namespace shakatube
