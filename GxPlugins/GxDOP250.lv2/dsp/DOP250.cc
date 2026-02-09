// generated from file './/DOP250.dsp' by dsp2cc:
// Code generated with Faust 0.9.90 (http://faust.grame.fr)

#include "diode_table.h"

namespace DOP250 {

class Dsp: public PluginLV2 {
private:
	uint32_t fSamplingFreq;
	double 	fConst0;
	double 	fConst1;
	double 	fConst2;
	double 	fConst3;
	double 	fConst4;
	double 	fConst5;
	FAUSTFLOAT 	fslider0;
	FAUSTFLOAT	*fslider0_;
	double 	fRec1[2];
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
	double 	fVec0[2];
	double 	fRec3[2];
	double 	fRec2[4];
	double 	fConst22;
	double 	fConst23;
	double 	fConst24;
	double 	fConst25;
	double 	fConst26;
	double 	fConst27;
	double 	fConst28;
	double 	fConst29;
	double 	fRec0[3];
	FAUSTFLOAT 	fslider1;
	FAUSTFLOAT	*fslider1_;
	double 	fRec4[2];
	double 	fConst30;

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
	id = "DOP250";
	name = N_("DOP250");
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
	for (int i=0; i<2; i++) fVec0[i] = 0;
	for (int i=0; i<2; i++) fRec3[i] = 0;
	for (int i=0; i<4; i++) fRec2[i] = 0;
	for (int i=0; i<3; i++) fRec0[i] = 0;
	for (int i=0; i<2; i++) fRec4[i] = 0;
}

void Dsp::clear_state_f_static(PluginLV2 *p)
{
	static_cast<Dsp*>(p)->clear_state_f();
}

inline void Dsp::init(uint32_t samplingFreq)
{
	fSamplingFreq = samplingFreq;
	fConst0 = double(min(1.92e+05, max(1.0, (double)fSamplingFreq)));
	fConst1 = (2.02242307799883e-10 * fConst0);
	fConst2 = (1.07575695638236e-05 + (fConst0 * (fConst1 - 1.11254784429064e-05)));
	fConst3 = (2.15151391276472e-05 - (4.04484615599767e-10 * faustpower<2>(fConst0)));
	fConst4 = (1.07575695638236e-05 + (fConst0 * (1.11254784429064e-05 + fConst1)));
	fConst5 = (1.0 / fConst4);
	fConst6 = (1.25177089698758e-14 * fConst0);
	fConst7 = ((fConst0 * (1.16405210306984e-09 + (fConst0 * (2.5041238200267e-10 + fConst6)))) - 2.44107917543592e-22);
	fConst8 = (1.17666464316832e-16 * fConst0);
	fConst9 = (2.47670660227637e-08 + (fConst0 * (5.33888839386713e-09 + (fConst0 * (2.62521807834115e-12 + fConst8)))));
	fConst10 = (1.22568007880329e-14 * fConst0);
	fConst11 = ((fConst0 * ((fConst0 * (2.45193032406485e-10 - fConst10)) - 1.14033291664283e-09)) - 2.39133877988791e-22);
	fConst12 = (1.15213927407509e-16 * fConst0);
	fConst13 = (2.4262402481764e-08 + (fConst0 * ((fConst0 * (4.92837629021427e-10 - fConst12)) - 7.50825799262758e-09)));
	fConst14 = ((fConst0 * ((fConst0 * (2.5041238200267e-10 - fConst6)) - 1.16405210306984e-09)) - 2.44107917543592e-22);
	fConst15 = (2.47670660227637e-08 + (fConst0 * ((fConst0 * (2.62521807834115e-12 - fConst8)) - 5.33888839386713e-09)));
	fConst16 = (3.75531269096275e-14 * fConst0);
	fConst17 = ((fConst0 * ((fConst0 * (fConst16 - 2.5041238200267e-10)) - 1.16405210306984e-09)) - 7.32323752630777e-22);
	fConst18 = (3.52999392950497e-16 * fConst0);
	fConst19 = (7.4301198068291e-08 + (fConst0 * ((fConst0 * (fConst18 - 2.62521807834115e-12)) - 5.33888839386713e-09)));
	fConst20 = ((fConst0 * (1.16405210306984e-09 + (fConst0 * (0 - (2.5041238200267e-10 + fConst16))))) - 7.32323752630777e-22);
	fConst21 = (7.4301198068291e-08 + (fConst0 * (5.33888839386713e-09 + (fConst0 * (0 - (2.62521807834115e-12 + fConst18))))));
	fConst22 = (3.67704023640987e-14 * fConst0);
	fConst23 = ((fConst0 * ((fConst0 * (fConst22 - 2.45193032406485e-10)) - 1.14033291664283e-09)) - 7.17401633966372e-22);
	fConst24 = (3.45641782222527e-16 * fConst0);
	fConst25 = (7.27872074452919e-08 + (fConst0 * ((fConst0 * (fConst24 - 4.92837629021427e-10)) - 7.50825799262758e-09)));
	fConst26 = ((fConst0 * (1.14033291664283e-09 + (fConst0 * (0 - (2.45193032406485e-10 + fConst22))))) - 7.17401633966372e-22);
	fConst27 = (7.27872074452919e-08 + (fConst0 * (7.50825799262758e-09 + (fConst0 * (0 - (4.92837629021427e-10 + fConst24))))));
	fConst28 = ((fConst0 * (1.14033291664283e-09 + (fConst0 * (2.45193032406485e-10 + fConst10)))) - 2.39133877988791e-22);
	fConst29 = (2.4262402481764e-08 + (fConst0 * (7.50825799262758e-09 + (fConst0 * (4.92837629021427e-10 + fConst12)))));
	fConst30 = (fConst0 / fConst4);
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
	double 	fSlow0 = (4.748558434412966e-05 * (exp((5 * (1 - double(fslider0)))) - 1));
	double 	fSlow1 = (4.748558434412966e-05 * (exp((7 * double(fslider1))) - 1));
	for (int i=0; i<count; i++) {
		fRec1[0] = (fSlow0 + (0.993 * fRec1[1]));
		double fTemp0 = (fConst9 + (fConst7 * fRec1[0]));
		double fTemp1 = (double)input0[i];
		fVec0[0] = fTemp1;
		fRec3[0] = ((fVec0[0] + fRec3[1]) - fVec0[1]);
		fRec2[0] = (fRec3[0] - ((((fRec2[1] * (fConst21 + (fConst20 * fRec1[0]))) + (fRec2[2] * (fConst19 + (fConst17 * fRec1[0])))) + (fRec2[3] * (fConst15 + (fConst14 * fRec1[0])))) / fTemp0));
		fRec0[0] = (diodeclip((((((fRec2[0] * (fConst29 + (fConst28 * fRec1[0]))) + (fRec2[1] * (fConst27 + (fConst26 * fRec1[0])))) + (fRec2[2] * (fConst25 + (fConst23 * fRec1[0])))) + (fRec2[3] * (fConst13 + (fConst11 * fRec1[0])))) / fTemp0)) - (fConst5 * ((fConst3 * fRec0[1]) + (fConst2 * fRec0[2]))));
		fRec4[0] = (fSlow1 + (0.993 * fRec4[1]));
		output0[i] = (FAUSTFLOAT)(fConst30 * ((fRec0[2] * (0 - (1.01121153899942e-05 * fRec4[0]))) + (1.01121153899942e-05 * (fRec4[0] * fRec0[0]))));
		// post processing
		fRec4[1] = fRec4[0];
		fRec0[2] = fRec0[1]; fRec0[1] = fRec0[0];
		for (int i=3; i>0; i--) fRec2[i] = fRec2[i-1];
		fRec3[1] = fRec3[0];
		fVec0[1] = fVec0[0];
		fRec1[1] = fRec1[0];
	}
#undef fslider0
#undef fslider1
}

void __rt_func Dsp::compute_static(int count, FAUSTFLOAT *input0, FAUSTFLOAT *output0, PluginLV2 *p)
{
	static_cast<Dsp*>(p)->compute(count, input0, output0);
}


void Dsp::connect(uint32_t port,void* data)
{
	switch ((PortIndex)port)
	{
	case GAIN: 
		fslider0_ = (float*)data; // , 0.5, 0.0, 1.0, 0.01 
		break;
	case LEVEL: 
		fslider1_ = (float*)data; // , 0.5, 0.0, 1.0, 0.01 
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
   GAIN, 
   LEVEL, 
} PortIndex;
*/

} // end namespace DOP250
