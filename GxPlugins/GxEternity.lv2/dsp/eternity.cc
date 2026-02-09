// generated from file '../dkbuild/eternity//eternity.dsp' by dsp2cc:
// Code generated with Faust 0.9.90 (http://faust.grame.fr)

#include "lovepedal_neg_table.h"
#include "lovepedal_table.h"
#include "math.h"

namespace eternity {

class Dsp: public PluginLV2 {
private:
	gx_resample::FixedRateResampler smp;
	uint32_t samplingFreq;
	uint32_t fSamplingFreq;
	FAUSTFLOAT 	fslider0;
	FAUSTFLOAT	*fslider0_;
	double 	fRec0[2];
	double 	fConst0;
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
	FAUSTFLOAT 	fslider1;
	FAUSTFLOAT	*fslider1_;
	double 	fRec2[2];
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
	double 	fConst28;
	double 	fRec3[5];
	double 	fConst29;
	double 	fConst30;
	double 	fConst31;
	double 	fConst32;
	double 	fConst33;
	double 	fConst34;
	double 	fConst35;
	double 	fConst36;
	double 	fRec1[3];
	FAUSTFLOAT 	fslider2;
	FAUSTFLOAT	*fslider2_;
	double 	fRec4[2];

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
	id = "eternity";
	name = N_("Eternity");
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
	for (int i=0; i<2; i++) fRec0[i] = 0;
	for (int i=0; i<2; i++) fRec2[i] = 0;
	for (int i=0; i<5; i++) fRec3[i] = 0;
	for (int i=0; i<3; i++) fRec1[i] = 0;
	for (int i=0; i<2; i++) fRec4[i] = 0;
}

void Dsp::clear_state_f_static(PluginLV2 *p)
{
	static_cast<Dsp*>(p)->clear_state_f();
}

inline void Dsp::init(uint32_t RsamplingFreq)
{
	samplingFreq = 2 * RsamplingFreq;
	smp.setup(RsamplingFreq, samplingFreq);
	fSamplingFreq = samplingFreq;
	fConst0 = double(min(1.92e+05, max(1.0, (double)fSamplingFreq)));
	fConst1 = (1.33353532692336e-09 * fConst0);
	fConst2 = (0 - (1.33353532692336e-10 + fConst1));
	fConst3 = (1.33353265987938e-09 * fConst0);
	fConst4 = (1.33353265987938e-10 + fConst3);
	fConst5 = (8.80161746458281e-11 * fConst0);
	fConst6 = (6.06162435238984e-07 + fConst5);
	fConst7 = (1.33353532692336e-10 - fConst1);
	fConst8 = (fConst3 - 1.33353265987938e-10);
	fConst9 = (fConst5 - 6.06162435238984e-07);
	fConst10 = faustpower<2>(fConst0);
	fConst11 = (1.74496147075981e-19 * fConst0);
	fConst12 = (9.29593259492128e-09 + (fConst0 * (4.32095947943305e-10 + (fConst0 * (1.18067847309604e-12 + (fConst0 * (8.97219720380579e-16 + fConst11)))))));
	fConst13 = (6.97984588303922e-21 * fConst0);
	fConst14 = (1.68406885543421e-07 + (fConst0 * (7.68136449511157e-09 + (fConst0 * (1.47069414495405e-11 + (fConst0 * (3.74857276915524e-15 + fConst13)))))));
	fConst15 = (1.16329306050615e-15 * fConst10);
	fConst16 = (fConst15 - 8.30116371802634e-10);
	fConst17 = (4.6531722420246e-17 * fConst10);
	fConst18 = (fConst17 - 1.50385463089454e-08);
	fConst19 = (9.29593259492128e-09 + (fConst0 * ((fConst0 * (1.18067847309604e-12 + (fConst0 * (fConst11 - 8.97219720380579e-16)))) - 4.32095947943305e-10)));
	fConst20 = (1.68406885543421e-07 + (fConst0 * ((fConst0 * (1.47069414495405e-11 + (fConst0 * (fConst13 - 3.74857276915524e-15)))) - 7.68136449511157e-09)));
	fConst21 = (6.97984588303922e-19 * fConst0);
	fConst22 = (3.71837303796851e-08 + (fConst0 * ((fConst10 * (1.79443944076116e-15 - fConst21)) - 8.6419189588661e-10)));
	fConst23 = (2.79193835321569e-20 * fConst0);
	fConst24 = (6.73627542173684e-07 + (fConst0 * ((fConst10 * (7.49714553831047e-15 - fConst23)) - 1.53627289902231e-08)));
	fConst25 = (5.57755955695277e-08 + (fConst10 * ((1.04697688245588e-18 * fConst10) - 2.36135694619208e-12)));
	fConst26 = (1.01044131326053e-06 + (fConst10 * ((4.18790752982353e-20 * fConst10) - 2.94138828990809e-11)));
	fConst27 = (3.71837303796851e-08 + (fConst0 * (8.6419189588661e-10 + (fConst10 * (0 - (1.79443944076116e-15 + fConst21))))));
	fConst28 = (6.73627542173684e-07 + (fConst0 * (1.53627289902231e-08 + (fConst10 * (0 - (7.49714553831047e-15 + fConst23))))));
	fConst29 = (8.30116371802634e-10 - fConst15);
	fConst30 = (1.50385463089454e-08 - fConst17);
	fConst31 = (5.81646530253075e-16 * fConst0);
	fConst32 = (4.15058185901317e-10 + (fConst0 * (7.43406787548609e-10 + fConst31)));
	fConst33 = (2.3265861210123e-17 * fConst0);
	fConst34 = (7.5192731544727e-09 + (fConst0 * (4.21117295924353e-11 + fConst33)));
	fConst35 = ((fConst0 * (7.43406787548609e-10 - fConst31)) - 4.15058185901317e-10);
	fConst36 = ((fConst0 * (4.21117295924353e-11 - fConst33)) - 7.5192731544727e-09);
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
	FAUSTFLOAT buf[smp.max_out_count(count)];
	int ReCount = smp.up(count, input0, buf);
	double 	fSlow0 = (0.007000000000000006 * (1 - double(fslider0)));
	double 	fSlow1 = (0.00036676987543879196 * (exp((3 * double(fslider1))) - 1));
	double 	fSlow2 = (0.007000000000000006 * double(fslider2));
	for (int i=0; i<ReCount; i++) {
		fRec0[0] = (fSlow0 + (0.993 * fRec0[1]));
		double fTemp0 = (6.0615363362152e-08 + (fConst0 * (fConst6 + (fRec0[0] * (fConst4 + (fConst2 * fRec0[0]))))));
		double fTemp1 = (fConst0 * (3.54716849793116e-10 + (fRec0[0] * (1.06681759336275e-09 - (1.33352199170344e-09 * fRec0[0])))));
		fRec2[0] = (fSlow1 + (0.993 * fRec2[1]));
		double fTemp2 = (fConst14 + (fConst12 * fRec2[0]));
		fRec3[0] = ((double)buf[i] - (((((fRec3[1] * (fConst28 + (fConst27 * fRec2[0]))) + (fRec3[2] * (fConst26 + (fConst25 * fRec2[0])))) + (fRec3[3] * (fConst24 + (fConst22 * fRec2[0])))) + (fRec3[4] * (fConst20 + (fConst19 * fRec2[0])))) / fTemp2));
		double fTemp3 = (fConst0 * (((fConst0 * (fRec3[2] * (0 - (8.42234591848707e-11 + (1.48681357509722e-09 * fRec2[0]))))) + ((fRec3[4] * (fConst36 + (fConst35 * fRec2[0]))) + (((fRec3[0] * (fConst34 + (fConst32 * fRec2[0]))) + (fRec3[1] * (fConst30 + (fConst29 * fRec2[0])))) + (fRec3[3] * (fConst18 + (fConst16 * fRec2[0])))))) / fTemp2));
		fRec1[0] = (((int(signbit(fTemp3)))?lovepedal_negclip(fTemp3):lovepedalclip(fTemp3)) - (((fRec1[1] * (1.21230726724304e-07 + (fConst10 * ((fRec0[0] * ((2.66707065384672e-09 * fRec0[0]) - 2.66706531975875e-09)) - 1.76032349291656e-10)))) + (fRec1[2] * (6.0615363362152e-08 + (fConst0 * (fConst9 + (fRec0[0] * (fConst8 + (fConst7 * fRec0[0])))))))) / fTemp0));
		fRec4[0] = (fSlow2 + (0.993 * fRec4[1]));
		buf[i] = (FAUSTFLOAT)(fConst0 * ((fRec4[0] * (((fConst0 * (fRec1[1] * ((fRec0[0] * ((2.66704398340689e-09 * fRec0[0]) - 2.13363518672551e-09)) - 7.09433699586232e-10))) + (fRec1[0] * (6.06146359865201e-07 + fTemp1))) + (fRec1[2] * (fTemp1 - 6.06146359865201e-07)))) / fTemp0));
		// post processing
		fRec4[1] = fRec4[0];
		fRec1[2] = fRec1[1]; fRec1[1] = fRec1[0];
		for (int i=4; i>0; i--) fRec3[i] = fRec3[i-1];
		fRec2[1] = fRec2[0];
		fRec0[1] = fRec0[0];
	}
	smp.down(buf, output0);
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
	case GLASS: 
		fslider0_ = (float*)data; // , 0.5, 0.0, 1.0, 0.01 
		break;
	case LEVEL: 
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
   GLASS, 
   LEVEL, 
} PortIndex;
*/

} // end namespace eternity
