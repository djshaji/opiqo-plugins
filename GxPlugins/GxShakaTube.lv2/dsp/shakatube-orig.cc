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
	double 	fConst29;
	double 	fConst30;
	double 	fConst31;
	double 	fConst32;
	double 	fConst33;
	double 	fRec4[4];
	double 	fConst34;
	double 	fConst35;
	double 	fConst36;
	double 	fConst37;
	double 	fRec2[6];
	double 	fConst38;
	double 	fConst39;
	double 	fConst40;
	double 	fConst41;
	double 	fConst42;
	double 	fConst43;
	double 	fConst44;
	double 	fConst45;
	double 	fConst46;
	double 	fConst47;
	double 	fConst48;
	double 	fConst49;
	double 	fConst50;
	double 	fConst51;
	double 	fConst52;
	double 	fRec0[4];
	FAUSTFLOAT 	fslider2;
	FAUSTFLOAT	*fslider2_;
	double 	fRec5[2];
	double 	fConst53;

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
	for (int i=0; i<4; i++) fRec4[i] = 0;
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
	fConst1 = (1.6104757871802e-15 * fConst0);
	fConst2 = (0.0106830192165377 + (fConst0 * ((fConst0 * (1.05302387697862e-10 - fConst1)) - 1.18457196098283e-05)));
	fConst3 = (4.83142736154061e-15 * fConst0);
	fConst4 = (0.0320490576496132 + (fConst0 * ((fConst0 * (fConst3 - 1.05302387697862e-10)) - 1.18457196098283e-05)));
	fConst5 = (0.0320490576496132 + (fConst0 * (1.18457196098283e-05 + (fConst0 * (0 - (1.05302387697862e-10 + fConst3))))));
	fConst6 = (0.0106830192165377 + (fConst0 * (1.18457196098283e-05 + (fConst0 * (1.05302387697862e-10 + fConst1)))));
	fConst7 = (1.0 / fConst6);
	fConst8 = (1.24736926967588e-23 * fConst0);
	fConst9 = ((fConst0 * (5.57818581186461e-22 - fConst8)) - 6.23635632769932e-21);
	fConst10 = (1.32698858476157e-20 * fConst0);
	fConst11 = (fConst10 - 5.93424022538789e-19);
	fConst12 = (3.77628398361412e-24 * fConst0);
	fConst13 = (1.05190110384002e-13 + (fConst0 * ((fConst0 * (3.08185104111474e-16 + (fConst0 * ((fConst0 * (7.06455362322565e-21 - fConst12)) - 2.582073179128e-18)))) - 1.03807230695891e-14)));
	fConst14 = (1.88814199180706e-23 * fConst0);
	fConst15 = (5.2595055192001e-13 + (fConst0 * ((fConst0 * (3.08185104111474e-16 + (fConst0 * (2.582073179128e-18 + (fConst0 * (fConst14 - 2.11936608696769e-20)))))) - 3.11421692087674e-14)));
	fConst16 = (3.77628398361412e-23 * fConst0);
	fConst17 = (1.05190110384002e-12 + (fConst0 * ((fConst0 * ((fConst0 * (5.164146358256e-18 + (fConst0 * (1.41291072464513e-20 - fConst16)))) - 6.16370208222947e-16)) - 2.07614461391783e-14)));
	fConst18 = (1.05190110384002e-12 + (fConst0 * (2.07614461391783e-14 + (fConst0 * ((fConst0 * ((fConst0 * (1.41291072464513e-20 + fConst16)) - 5.164146358256e-18)) - 6.16370208222947e-16)))));
	fConst19 = (5.2595055192001e-13 + (fConst0 * (3.11421692087674e-14 + (fConst0 * (3.08185104111474e-16 + (fConst0 * ((fConst0 * (0 - (2.11936608696769e-20 + fConst14))) - 2.582073179128e-18)))))));
	fConst20 = (1.05190110384002e-13 + (fConst0 * (1.03807230695891e-14 + (fConst0 * (3.08185104111474e-16 + (fConst0 * (2.582073179128e-18 + (fConst0 * (7.06455362322565e-21 + fConst12)))))))));
	fConst21 = (1.0 / fConst20);
	fConst22 = (9.63245349847197e-15 * fConst0);
	fConst23 = (7.67840464353146e-10 + (fConst0 * (1.15097032777674e-11 + fConst22)));
	fConst24 = (1.92649069969439e-10 * fConst0);
	fConst25 = (2.12680688873712e-07 + fConst24);
	fConst26 = (9.63235717490022e-15 * fConst0);
	fConst27 = (8.75768341903893e-08 - fConst26);
	fConst28 = ((fConst0 * (1.15097032777674e-11 - fConst22)) - 7.67840464353146e-10);
	fConst29 = (fConst24 - 2.12680688873712e-07);
	fConst30 = (2.88973604954159e-14 * fConst0);
	fConst31 = (7.67840464353146e-10 + (fConst0 * (0 - (1.15097032777674e-11 + fConst30))));
	fConst32 = (2.12680688873712e-07 - fConst24);
	fConst33 = ((fConst0 * (fConst30 - 1.15097032777674e-11)) - 7.67840464353146e-10);
	fConst34 = (2.88970715247007e-14 * fConst0);
	fConst35 = (fConst34 - 8.75768341903893e-08);
	fConst36 = (0 - (8.75768341903893e-08 + fConst34));
	fConst37 = (8.75768341903893e-08 + fConst26);
	fConst38 = (6.2368463483794e-23 * fConst0);
	fConst39 = (6.23635632769932e-21 + (fConst0 * (fConst38 - 1.67345574355938e-21)));
	fConst40 = (3.98096575428472e-20 * fConst0);
	fConst41 = (5.93424022538789e-19 - fConst40);
	fConst42 = (1.24736926967588e-22 * fConst0);
	fConst43 = (1.24727126553986e-20 + (fConst0 * (1.11563716237292e-21 - fConst42)));
	fConst44 = (2.65397716952315e-20 * fConst0);
	fConst45 = (1.18684804507758e-18 + fConst44);
	fConst46 = ((fConst0 * (1.11563716237292e-21 + fConst42)) - 1.24727126553986e-20);
	fConst47 = (fConst44 - 1.18684804507758e-18);
	fConst48 = ((fConst0 * (0 - (1.67345574355938e-21 + fConst38))) - 6.23635632769932e-21);
	fConst49 = (0 - (5.93424022538789e-19 + fConst40));
	fConst50 = (6.23635632769932e-21 + (fConst0 * (5.57818581186461e-22 + fConst8)));
	fConst51 = (5.93424022538789e-19 + fConst10);
	fConst52 = (faustpower<2>(fConst0) / fConst20);
	fConst53 = (fConst0 / fConst6);
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
		double fTemp0 = (1.41147258344646e-05 + (fConst0 * (fConst25 + (fConst23 * fRec3[0]))));
		fRec4[0] = ((double)input0[i] - (((fRec4[2] * (4.23441775033937e-05 + (fConst0 * ((fConst33 * fRec3[0]) - fConst25)))) + ((fRec4[1] * (4.23441775033937e-05 + (fConst0 * (fConst32 + (fConst31 * fRec3[0]))))) + (fRec4[3] * (1.41147258344646e-05 + (fConst0 * (fConst29 + (fConst28 * fRec3[0]))))))) / fTemp0));
		fRec2[0] = ((fConst0 * (((((fRec4[0] * (1.99015644109509e-07 + (fConst0 * (1.92647143498004e-10 + (fConst37 * fRec3[0]))))) + (fRec4[1] * (1.99015644109509e-07 + (fConst0 * ((fConst36 * fRec3[0]) - 1.92647143498004e-10))))) + (fRec4[2] * ((fConst0 * ((fConst35 * fRec3[0]) - 1.92647143498004e-10)) - 1.99015644109509e-07))) + (fRec4[3] * ((fConst0 * (1.92647143498004e-10 + (fConst27 * fRec3[0]))) - 1.99015644109509e-07))) / fTemp0)) - (fConst21 * (((((fConst19 * fRec2[1]) + (fConst18 * fRec2[2])) + (fConst17 * fRec2[3])) + (fConst15 * fRec2[4])) + (fConst13 * fRec2[5]))));
		fRec0[0] = (tubeclip((fConst52 * ((((((fRec2[0] * (6.63442162521205e-18 + (fConst0 * (fConst51 + (fConst50 * fRec1[0]))))) + (fRec2[1] * (6.63442162521205e-18 + (fConst0 * (fConst49 + (fConst48 * fRec1[0])))))) + (fRec2[2] * ((fConst0 * (fConst47 + (fConst46 * fRec1[0]))) - 1.32688432504241e-17))) + (fRec2[3] * ((fConst0 * (fConst45 + (fConst43 * fRec1[0]))) - 1.32688432504241e-17))) + (fRec2[4] * (6.63442162521205e-18 + (fConst0 * (fConst41 + (fConst39 * fRec1[0])))))) + (fRec2[5] * (6.63442162521205e-18 + (fConst0 * (fConst11 + (fConst9 * fRec1[0])))))))) - (fConst7 * (((fConst5 * fRec0[1]) + (fConst4 * fRec0[2])) + (fConst2 * fRec0[3]))));
		fRec5[0] = (fSlow2 + (0.993 * fRec5[1]));
		output0[i] = (FAUSTFLOAT)(fConst53 * ((1.17512036261553e-05 * (fRec5[0] * (fRec0[1] + fRec0[0]))) + ((0 - (1.17512036261553e-05 * fRec5[0])) * (fRec0[2] + fRec0[3]))));
		// post processing
		fRec5[1] = fRec5[0];
		for (int i=3; i>0; i--) fRec0[i] = fRec0[i-1];
		for (int i=5; i>0; i--) fRec2[i] = fRec2[i-1];
		for (int i=3; i>0; i--) fRec4[i] = fRec4[i-1];
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
