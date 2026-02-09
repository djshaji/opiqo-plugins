// generated from file './/clubdrive.dsp' by dsp2cc:
// Code generated with Faust 2.15.11 (https://faust.grame.fr)

#include "clubman_p2_neg_table.h"
#include "clubman_p2_table.h"
#include "math.h"

namespace clubdrive {

class Dsp: public PluginLV2 {
private:
	gx_resample::FixedRateResampler smp;
	uint32_t samplingFreq;
	uint32_t fSamplingFreq;
	double fConst0;
	double fConst1;
	FAUSTFLOAT fVslider0;
	FAUSTFLOAT	*fVslider0_;
	double fRec3[2];
	double fConst2;
	double fConst3;
	double fConst4;
	double fConst5;
	double fConst6;
	double fConst7;
	double fConst8;
	double fConst9;
	FAUSTFLOAT fVslider1;
	FAUSTFLOAT	*fVslider1_;
	double fRec7[2];
	double fConst10;
	double fConst11;
	double fConst12;
	double fConst13;
	double fConst14;
	double fConst15;
	double fConst16;
	double fConst17;
	double fConst18;
	double fConst19;
	double fConst20;
	double fConst21;
	double fConst22;
	double fConst23;
	double fConst24;
	double fConst25;
	double fConst26;
	double fConst27;
	double fConst28;
	double fRec6[5];
	double fConst29;
	double fConst30;
	double fConst31;
	double fConst32;
	double fConst33;
	double fConst34;
	double fConst35;
	double fConst36;
	double fConst37;
	double fConst38;
	double fConst39;
	double fConst40;
	double fConst41;
	double fConst42;
	double fConst43;
	double fConst44;
	double fConst45;
	double fConst46;
	double fConst47;
	double fConst48;
	double fConst49;
	double fConst50;
	double fConst51;
	double fConst52;
	double fConst53;
	double fConst54;
	double fConst55;
	double fConst56;
	double fConst57;
	double fConst58;
	double fRec5[7];
	double fConst59;
	double fConst60;
	double fConst61;
	double fConst62;
	double fConst63;
	double fConst64;
	double fConst65;
	double fConst66;
	double fConst67;
	double fConst68;
	double fRec4[2];
	double fRec0[2];
	int iRec1[2];
	double fRec2[2];
	FAUSTFLOAT fVbargraph0;
	FAUSTFLOAT	*fVbargraph0_;

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
	id = "clubdrive";
	name = N_("clubdrive");
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
	for (int l0 = 0; (l0 < 2); l0 = (l0 + 1)) fRec3[l0] = 0.0;
	for (int l1 = 0; (l1 < 2); l1 = (l1 + 1)) fRec7[l1] = 0.0;
	for (int l2 = 0; (l2 < 5); l2 = (l2 + 1)) fRec6[l2] = 0.0;
	for (int l3 = 0; (l3 < 7); l3 = (l3 + 1)) fRec5[l3] = 0.0;
	for (int l4 = 0; (l4 < 2); l4 = (l4 + 1)) fRec4[l4] = 0.0;
	for (int l5 = 0; (l5 < 2); l5 = (l5 + 1)) fRec0[l5] = 0.0;
	for (int l6 = 0; (l6 < 2); l6 = (l6 + 1)) iRec1[l6] = 0;
	for (int l7 = 0; (l7 < 2); l7 = (l7 + 1)) fRec2[l7] = 0.0;
}

void Dsp::clear_state_f_static(PluginLV2 *p)
{
	static_cast<Dsp*>(p)->clear_state_f();
}

inline void Dsp::init(uint32_t RsamplingFreq)
{
	samplingFreq = 96000;
	smp.setup(RsamplingFreq, samplingFreq);
	fSamplingFreq = samplingFreq;
	fConst0 = std::min<double>(192000.0, std::max<double>(1.0, double(fSamplingFreq)));
	fConst1 = (1.0 / fConst0);
	fConst2 = mydsp_faustpower2_f(fConst0);
	fConst3 = (3.4429596770072001e-29 * fConst0);
	fConst4 = (((((((((((fConst3 + 1.8117538779657801e-24) * fConst0) + 2.05973637471007e-20) * fConst0) + 7.1020806922137504e-17) * fConst0) + 3.0319006647858102e-14) * fConst0) + 1.28274692825627e-12) * fConst0) + 4.2935330595462204e-12);
	fConst5 = (fConst2 / fConst4);
	fConst6 = (1.7823224136104001e-20 * fConst0);
	fConst7 = (((-9.1912371189730204e-17 - fConst6) * fConst0) + -9.5762003740081498e-15);
	fConst8 = (3.1088310920851501e-19 * fConst0);
	fConst9 = ((((-2.3527842552267399e-15 - fConst8) * fConst2) + 2.3991050598911102e-12) * fConst0);
	fConst10 = (1.5085328537672501e-18 * fConst0);
	fConst11 = (((-3.7071649926232299e-15 - fConst10) * fConst2) + 3.7847752897351798e-12);
	fConst12 = (1.8194159629757698e-18 * fConst0);
	fConst13 = (((fConst12 + 3.1012005364829101e-15) * fConst2) + -1.0522730054357601e-12);
	fConst14 = (((4.6632466381277303e-19 * fConst2) + -2.03958020491798e-13) * fConst2);
	fConst15 = ((2.26279928065088e-18 * fConst2) + -3.1865188462664399e-13);
	fConst16 = (2.3791286160379098e-13 - (2.7291239444636501e-18 * fConst2));
	fConst17 = ((((2.3527842552267399e-15 - fConst8) * fConst2) + -2.3991050598911102e-12) * fConst0);
	fConst18 = (((3.7071649926232299e-15 - fConst10) * fConst2) + -3.7847752897351798e-12);
	fConst19 = (((fConst12 + -3.1012005364829101e-15) * fConst2) + 1.0522730054357601e-12);
	fConst20 = (7.7720777302128802e-20 * fConst0);
	fConst21 = ((((((fConst20 + -1.1763921276133699e-15) * fConst0) + 1.01979010245899e-13) * fConst0) + -1.1995525299455599e-12) * fConst0);
	fConst22 = (3.7713321344181401e-19 * fConst0);
	fConst23 = (((((fConst22 + -1.8535824963116098e-15) * fConst0) + 1.59325942313322e-13) * fConst0) + -1.8923876448675899e-12);
	fConst24 = (4.5485399074394198e-19 * fConst0);
	fConst25 = (((((1.55060026824146e-15 - fConst24) * fConst0) + -1.18956430801896e-13) * fConst0) + 5.2613650271787903e-13);
	fConst26 = ((((((fConst20 + 1.1763921276133699e-15) * fConst0) + 1.01979010245899e-13) * fConst0) + 1.1995525299455599e-12) * fConst0);
	fConst27 = (((((fConst22 + 1.8535824963116098e-15) * fConst0) + 1.59325942313322e-13) * fConst0) + 1.8923876448675899e-12);
	fConst28 = (((((-1.55060026824146e-15 - fConst24) * fConst0) + -1.18956430801896e-13) * fConst0) + -5.2613650271787903e-13);
	fConst29 = (6.7060566756488397e-19 * fConst0);
	fConst30 = (((((-1.8681705669581299e-15 - fConst29) * fConst0) + -1.4930005840766301e-14) * fConst0) + 1.7313594790586899e-14);
	fConst31 = (6.6389961088923502e-17 * fConst0);
	fConst32 = (((((-1.86811679649868e-13 - fConst31) * fConst0) + -1.4930068169707499e-12) * fConst0) + 1.73135947905869e-12);
	fConst33 = (6.7060566756488399e-17 * fConst0);
	fConst34 = ((((fConst33 + 5.3770459445607203e-16) * fConst0) + -6.23289412461129e-16) * fConst0);
	fConst35 = (2.6824226702595401e-18 * fConst0);
	fConst36 = (((fConst35 + 3.7363411339162598e-15) * fConst2) + 3.4627189581173798e-14);
	fConst37 = (2.6555984435569401e-16 * fConst0);
	fConst38 = (((fConst37 + 3.73623359299736e-13) * fConst2) + 3.46271895811738e-12);
	fConst39 = (2.6824226702595399e-16 * fConst0);
	fConst40 = ((-1.0754091889121399e-15 - fConst39) * fConst2);
	fConst41 = (2.9860011681532501e-14 - (4.0236340053893e-18 * fConst2));
	fConst42 = (2.9860136339414999e-12 - (3.9833976653354099e-16 * fConst2));
	fConst43 = ((4.0236340053893002e-16 * fConst2) + 1.24657882492226e-15);
	fConst44 = (((fConst35 + -3.7363411339162598e-15) * fConst2) + -3.4627189581173798e-14);
	fConst45 = (((fConst37 + -3.73623359299736e-13) * fConst2) + -3.46271895811738e-12);
	fConst46 = ((1.0754091889121399e-15 - fConst39) * fConst2);
	fConst47 = (((((1.8681705669581299e-15 - fConst29) * fConst0) + -1.4930005840766301e-14) * fConst0) + -1.7313594790586899e-14);
	fConst48 = (((((1.86811679649868e-13 - fConst31) * fConst0) + -1.4930068169707499e-12) * fConst0) + -1.73135947905869e-12);
	fConst49 = ((((fConst33 + -5.3770459445607203e-16) * fConst0) + -6.23289412461129e-16) * fConst0);
	fConst50 = (1.0 / fConst4);
	fConst51 = (2.0657758062043202e-28 * fConst0);
	fConst52 = (((((((((-7.2470155118631101e-24 - fConst51) * fConst0) + -4.11947274942014e-20) * fConst2) + 6.0638013295716304e-14) * fConst0) + 5.13098771302508e-12) * fConst0) + 2.5761198357277301e-11);
	fConst53 = (5.1644395155107897e-28 * fConst0);
	fConst54 = (((((((((((fConst53 + 9.0587693898288895e-24) * fConst0) + -2.05973637471007e-20) * fConst0) + -2.1306242076641299e-16) * fConst0) + -3.0319006647858102e-14) * fConst0) + 6.4137346412813502e-12) * fConst0) + 6.4402995893193305e-11);
	fConst55 = (((((8.2389454988402703e-20 - (6.8859193540143901e-28 * fConst2)) * fConst2) + -1.2127602659143301e-13) * fConst2) + 8.5870661190924398e-11);
	fConst56 = (((((((((((fConst53 + -9.0587693898288895e-24) * fConst0) + -2.05973637471007e-20) * fConst0) + 2.1306242076641299e-16) * fConst0) + -3.0319006647858102e-14) * fConst0) + -6.4137346412813502e-12) * fConst0) + 6.4402995893193305e-11);
	fConst57 = (((((((((7.2470155118631101e-24 - fConst51) * fConst0) + -4.11947274942014e-20) * fConst2) + 6.0638013295716304e-14) * fConst0) + -5.13098771302508e-12) * fConst0) + 2.5761198357277301e-11);
	fConst58 = (((((((((((fConst3 + -1.8117538779657801e-24) * fConst0) + 2.05973637471007e-20) * fConst0) + -7.1020806922137504e-17) * fConst0) + 3.0319006647858102e-14) * fConst0) + -1.28274692825627e-12) * fConst0) + 4.2935330595462204e-12);
	fConst59 = ((3.56464482722079e-20 * fConst2) + -1.91524007480163e-14);
	fConst60 = (((fConst6 + 2.7573711356919101e-16) * fConst0) + 9.5762003740081498e-15);
	fConst61 = (3.8304801496032599e-14 - (7.1292896544415896e-20 * fConst2));
	fConst62 = (((fConst6 + -2.7573711356919101e-16) * fConst0) + 9.5762003740081498e-15);
	fConst63 = (((9.1912371189730204e-17 - fConst6) * fConst0) + -9.5762003740081498e-15);
	fConst64 = (2.2491408528328199e-06 * fConst0);
	fConst65 = (fConst64 + -0.112461932029384);
	fConst66 = (2.6891901501261999e-06 * fConst0);
	fConst67 = (2.91410423540948e-07 * fConst0);
	fConst68 = (-0.112461932029384 - fConst64);
	fVslider0 = FAUSTFLOAT(0.5);
	fVslider1 = FAUSTFLOAT(0.5);
	clear_state_f();
}

void Dsp::init_static(uint32_t samplingFreq, PluginLV2 *p)
{
	static_cast<Dsp*>(p)->init(samplingFreq);
}

void always_inline Dsp::compute(int count, FAUSTFLOAT *input0, FAUSTFLOAT *output0)
{
#define fVslider0 (*fVslider0_)
#define fVslider1 (*fVslider1_)
#define fVbargraph0 (*fVbargraph0_)
	FAUSTFLOAT buf[smp.max_out_count(count)];
	int ReCount = smp.up(count, input0, buf);
	double fSlow0 = (0.0070000000000000062 * double(fVslider0));
	double fSlow1 = (0.00036676987543879196 * (std::exp((3.0 * double(fVslider1))) + -1.0));
	for (int i = 0; (i < ReCount); i = (i + 1)) {
		int iTemp0 = (iRec1[1] < 4096);
		fRec3[0] = (fSlow0 + (0.99299999999999999 * fRec3[1]));
		fRec7[0] = (fSlow1 + (0.99299999999999999 * fRec7[1]));
		double fTemp1 = (fConst26 + ((fRec7[0] * ((fConst0 * (fConst27 + (fConst28 * fRec7[0]))) + 5.5758425468194001e-12)) + 3.5127808044962202e-12));
		fRec6[0] = (double(buf[i]) - (((((fRec6[1] * (fConst9 + ((fRec7[0] * ((fConst0 * (fConst11 + (fConst13 * fRec7[0]))) + 2.2303370187277601e-11)) + 1.40511232179849e-11))) + (fRec6[2] * (fConst14 + ((fRec7[0] * ((fConst2 * (fConst15 + (fConst16 * fRec7[0]))) + 3.3455055280916399e-11)) + 2.1076684826977399e-11)))) + (fRec6[3] * (fConst17 + ((fRec7[0] * ((fConst0 * (fConst18 + (fConst19 * fRec7[0]))) + 2.2303370187277601e-11)) + 1.40511232179849e-11)))) + (fRec6[4] * (fConst21 + ((fRec7[0] * ((fConst0 * (fConst23 + (fConst25 * fRec7[0]))) + 5.5758425468194001e-12)) + 3.5127808044962202e-12)))) / fTemp1));
		double fTemp2 = (fConst0 * ((((((fRec6[0] * (fConst30 + (fRec7[0] * (fConst32 + (fConst34 * fRec7[0]))))) + (fRec6[1] * (fConst36 + (fRec7[0] * (fConst38 + (fConst40 * fRec7[0])))))) + (fConst0 * (fRec6[2] * (fConst41 + (fRec7[0] * (fConst42 + (fConst43 * fRec7[0]))))))) + (fRec6[3] * (fConst44 + (fRec7[0] * (fConst45 + (fConst46 * fRec7[0])))))) + (fRec6[4] * (fConst47 + (fRec7[0] * (fConst48 + (fConst49 * fRec7[0])))))) / fTemp1));
		fRec5[0] = ((0.40000000000000002 * (int(signbit(double(fTemp2)))?double(clubman_p2_negclip(double(fTemp2))):double(clubman_p2clip(double(fTemp2))))) - (fConst50 * ((((((fConst52 * fRec5[1]) + (fConst54 * fRec5[2])) + (fConst55 * fRec5[3])) + (fConst56 * fRec5[4])) + (fConst57 * fRec5[5])) + (fConst58 * fRec5[6]))));
		double fTemp3 = (fConst67 + ((fRec3[0] * (fConst66 + ((fConst68 * fRec3[0]) + -0.99009478393054995))) + 1.4716243012736201));
		fRec4[0] = ((fConst5 * (((((((fConst7 * fRec5[0]) + (fConst59 * fRec5[1])) + (fConst60 * fRec5[2])) + (fConst61 * fRec5[3])) + (fConst62 * fRec5[4])) + (fConst59 * fRec5[5])) + (fConst63 * fRec5[6]))) - ((fRec4[1] * (((fRec3[0] * (((fConst65 * fRec3[0]) + -0.99009478393054995) - fConst66)) + 1.4716243012736201) - fConst67)) / fTemp3));
		double fTemp4 = ((((fRec3[0] * ((0.48893877427156401 * fRec3[0]) + -1.6134979550961599)) + -0.166239183252332) * (fRec4[0] + fRec4[1])) / fTemp3);
		double fTemp5 = std::max<double>(fConst1, std::fabs(fTemp4));
		fRec0[0] = (iTemp0?std::max<double>(fRec0[1], fTemp5):fTemp5);
		iRec1[0] = (iTemp0?(iRec1[1] + 1):1);
		fRec2[0] = (iTemp0?fRec2[1]:fRec0[1]);
		fVbargraph0 = FAUSTFLOAT(fRec2[0]);
		buf[i] = FAUSTFLOAT(fTemp4);
		fRec3[1] = fRec3[0];
		fRec7[1] = fRec7[0];
		for (int j0 = 4; (j0 > 0); j0 = (j0 - 1)) {
			fRec6[j0] = fRec6[(j0 - 1)];
		}
		for (int j1 = 6; (j1 > 0); j1 = (j1 - 1)) {
			fRec5[j1] = fRec5[(j1 - 1)];
		}
		fRec4[1] = fRec4[0];
		fRec0[1] = fRec0[0];
		iRec1[1] = iRec1[0];
		fRec2[1] = fRec2[0];
	}
	smp.down(buf, output0);
#undef fVslider0
#undef fVslider1
#undef fVbargraph0
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
		fVslider1_ = (float*)data; // , 0.5, 0.0, 1.0, 0.01 
		break;
	case VOLUME: 
		fVslider0_ = (float*)data; // , 0.5, 0.0, 1.0, 0.01 
		break;
	case V1: 
		fVbargraph0_ = (float*)data; // , -70.0, -70.0, 4.0, 0.00001 
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
   VOLUME, 
   V1, 
} PortIndex;
*/

} // end namespace clubdrive
