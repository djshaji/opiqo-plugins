// generated from file '../dkbuild/supersonic//supersonic.dsp' by dsp2cc:
// Code generated with Faust 0.9.90 (http://faust.grame.fr)

#include "supersonic_table.h"

namespace supersonic {

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
	FAUSTFLOAT 	fslider0;
	FAUSTFLOAT	*fslider0_;
	double 	fRec2[2];
	double 	fConst25;
	double 	fConst26;
	double 	fConst27;
	double 	fConst28;
	double 	fConst29;
	double 	fConst30;
	FAUSTFLOAT 	fslider1;
	FAUSTFLOAT	*fslider1_;
	double 	fRec3[2];
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
	double 	fConst44;
	double 	fConst45;
	double 	fConst46;
	double 	fConst47;
	double 	fConst48;
	double 	fConst49;
	double 	fConst50;
	double 	fConst51;
	double 	fConst52;
	double 	fConst53;
	double 	fConst54;
	double 	fConst55;
	double 	fConst56;
	double 	fConst57;
	double 	fConst58;
	double 	fConst59;
	double 	fConst60;
	double 	fConst61;
	double 	fConst62;
	double 	fConst63;
	double 	fConst64;
	double 	fConst65;
	double 	fConst66;
	double 	fConst67;
	double 	fConst68;
	double 	fConst69;
	double 	fConst70;
	double 	fConst71;
	double 	fConst72;
	double 	fConst73;
	double 	fConst74;
	double 	fConst75;
	double 	fConst76;
	double 	fConst77;
	double 	fConst78;
	double 	fConst79;
	double 	fConst80;
	double 	fConst81;
	double 	fConst82;
	double 	fConst83;
	double 	fConst84;
	double 	fConst85;
	double 	fConst86;
	double 	fConst87;
	double 	fConst88;
	double 	fConst89;
	double 	fConst90;
	double 	fConst91;
	double 	fConst92;
	double 	fConst93;
	double 	fConst94;
	double 	fConst95;
	double 	fConst96;
	double 	fConst97;
	double 	fConst98;
	double 	fConst99;
	double 	fConst100;
	double 	fConst101;
	double 	fConst102;
	double 	fConst103;
	double 	fConst104;
	double 	fConst105;
	double 	fConst106;
	double 	fConst107;
	double 	fConst108;
	double 	fConst109;
	double 	fConst110;
	double 	fConst111;
	double 	fConst112;
	double 	fConst113;
	double 	fConst114;
	double 	fConst115;
	double 	fConst116;
	double 	fConst117;
	double 	fConst118;
	double 	fConst119;
	double 	fConst120;
	double 	fConst121;
	double 	fConst122;
	double 	fConst123;
	double 	fConst124;
	double 	fConst125;
	double 	fConst126;
	double 	fConst127;
	double 	fConst128;
	double 	fConst129;
	double 	fConst130;
	double 	fConst131;
	double 	fConst132;
	double 	fConst133;
	FAUSTFLOAT 	fslider2;
	FAUSTFLOAT	*fslider2_;
	double 	fRec5[2];
	double 	fRec6[2];
	double 	fRec4[7];
	double 	fConst134;
	double 	fConst135;
	double 	fConst136;
	double 	fConst137;
	double 	fConst138;
	double 	fConst139;
	double 	fConst140;
	double 	fConst141;
	double 	fConst142;
	double 	fConst143;
	double 	fConst144;
	double 	fConst145;
	double 	fConst146;
	double 	fConst147;
	double 	fConst148;
	double 	fConst149;
	double 	fConst150;
	double 	fConst151;
	double 	fConst152;
	double 	fConst153;
	double 	fConst154;
	double 	fConst155;
	double 	fConst156;
	double 	fConst157;
	double 	fConst158;
	double 	fConst159;
	double 	fConst160;
	double 	fConst161;
	double 	fConst162;
	double 	fConst163;
	double 	fConst164;
	double 	fConst165;
	double 	fConst166;
	double 	fConst167;
	double 	fConst168;
	double 	fConst169;
	double 	fConst170;
	double 	fConst171;
	double 	fConst172;
	double 	fConst173;
	double 	fConst174;
	double 	fConst175;
	double 	fConst176;
	double 	fConst177;
	double 	fConst178;
	double 	fConst179;
	double 	fConst180;
	double 	fConst181;
	double 	fConst182;
	double 	fConst183;
	double 	fConst184;
	double 	fConst185;
	double 	fConst186;
	double 	fConst187;
	double 	fConst188;
	double 	fConst189;
	double 	fConst190;
	double 	fConst191;
	double 	fConst192;
	double 	fConst193;
	double 	fConst194;
	double 	fConst195;
	double 	fConst196;
	double 	fConst197;
	double 	fConst198;
	double 	fConst199;
	double 	fConst200;
	double 	fConst201;
	double 	fRec1[6];
	double 	fConst202;
	double 	fConst203;
	double 	fConst204;
	double 	fConst205;
	double 	fConst206;
	double 	fConst207;
	double 	fConst208;
	double 	fConst209;
	double 	fConst210;
	double 	fRec0[9];
	double 	fConst211;
	double 	fConst212;
	double 	fConst213;
	double 	fConst214;
	double 	fConst215;
	double 	fConst216;
	double 	fConst217;
	double 	fConst218;
	double 	fConst219;
	double 	fConst220;
	double 	fConst221;
	double 	fConst222;
	double 	fConst223;
	double 	fConst224;

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
	id = "supersonic";
	name = N_("Supersonic");
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
	for (int i=0; i<2; i++) fRec2[i] = 0;
	for (int i=0; i<2; i++) fRec3[i] = 0;
	for (int i=0; i<2; i++) fRec5[i] = 0;
	for (int i=0; i<2; i++) fRec6[i] = 0;
	for (int i=0; i<7; i++) fRec4[i] = 0;
	for (int i=0; i<6; i++) fRec1[i] = 0;
	for (int i=0; i<9; i++) fRec0[i] = 0;
}

void Dsp::clear_state_f_static(PluginLV2 *p)
{
	static_cast<Dsp*>(p)->clear_state_f();
}

inline void Dsp::init(uint32_t samplingFreq)
{
	fSamplingFreq = samplingFreq;
	fConst0 = double(min(1.92e+05, max(1.0, (double)fSamplingFreq)));
	fConst1 = (1.03166468453596e-39 * fConst0);
	fConst2 = (7.23454404936606e-10 + (fConst0 * ((fConst0 * (3.48098546144324e-14 + (fConst0 * ((fConst0 * (1.03357108589895e-20 + (fConst0 * ((fConst0 * (3.29454001779334e-29 + (fConst0 * (fConst1 - 3.18357714768969e-34)))) - 1.23122315470738e-24)))) - 1.12318322365961e-16)))) - 1.0201961576646e-11)));
	fConst3 = (8.25331747628768e-39 * fConst0);
	fConst4 = faustpower<2>(fConst0);
	fConst5 = (5.78763523949285e-09 + (fConst0 * ((fConst0 * (1.3923941845773e-13 + (fConst0 * ((fConst4 * (2.46244630941476e-24 + (fConst0 * ((fConst0 * (1.91014628861382e-33 - fConst3)) - 1.31781600711734e-28)))) - 2.24636644731921e-16)))) - 6.12117694598759e-11)));
	fConst6 = (2.88866111670069e-38 * fConst0);
	fConst7 = (2.0256723338225e-08 + (fConst0 * ((fConst0 * (1.3923941845773e-13 + (fConst0 * (2.24636644731921e-16 + (fConst0 * ((fConst0 * (2.46244630941476e-24 + (fConst0 * (1.31781600711734e-28 + (fConst0 * (fConst6 - 4.45700800676557e-33)))))) - 4.1342843435958e-20)))))) - 1.42827462073044e-10)));
	fConst8 = (5.77732223340138e-38 * fConst0);
	fConst9 = (4.05134466764499e-08 + (fConst0 * ((fConst0 * ((fConst0 * (6.73909934195763e-16 + (fConst4 * ((fConst0 * (1.31781600711734e-28 + (fConst0 * (4.45700800676557e-33 - fConst8)))) - 7.38733892824429e-24)))) - 1.3923941845773e-13)) - 1.42827462073044e-10)));
	fConst10 = (5.06418083455624e-08 + (fConst4 * ((fConst4 * (6.20142651539371e-20 + (fConst4 * ((7.22165279175172e-38 * fConst4) - 3.29454001779334e-28)))) - 3.48098546144324e-13)));
	fConst11 = (4.05134466764499e-08 + (fConst0 * (1.42827462073044e-10 + (fConst0 * ((fConst0 * ((fConst4 * (7.38733892824429e-24 + (fConst0 * (1.31781600711734e-28 + (fConst0 * (0 - (4.45700800676557e-33 + fConst8))))))) - 6.73909934195763e-16)) - 1.3923941845773e-13)))));
	fConst12 = (2.0256723338225e-08 + (fConst0 * (1.42827462073044e-10 + (fConst0 * (1.3923941845773e-13 + (fConst0 * ((fConst0 * ((fConst0 * ((fConst0 * (1.31781600711734e-28 + (fConst0 * (4.45700800676557e-33 + fConst6)))) - 2.46244630941476e-24)) - 4.1342843435958e-20)) - 2.24636644731921e-16)))))));
	fConst13 = (5.78763523949285e-09 + (fConst0 * (6.12117694598759e-11 + (fConst0 * (1.3923941845773e-13 + (fConst0 * (2.24636644731921e-16 + (fConst4 * ((fConst0 * ((fConst0 * (0 - (1.91014628861382e-33 + fConst3))) - 1.31781600711734e-28)) - 2.46244630941476e-24)))))))));
	fConst14 = (7.23454404936606e-10 + (fConst0 * (1.0201961576646e-11 + (fConst0 * (3.48098546144324e-14 + (fConst0 * (1.12318322365961e-16 + (fConst0 * (1.03357108589895e-20 + (fConst0 * (1.23122315470738e-24 + (fConst0 * (3.29454001779334e-29 + (fConst0 * (3.18357714768969e-34 + fConst1)))))))))))))));
	fConst15 = (1.0 / fConst14);
	fConst16 = (5.06350333062866e-27 * fConst0);
	fConst17 = (2.79301683442722e-14 + (fConst0 * ((fConst0 * (6.79263055101936e-16 + (fConst0 * ((fConst0 * (1.8761602639722e-19 - fConst16)) - 2.49956394010291e-17)))) - 2.10837206855494e-15)));
	fConst18 = (2.53175166531433e-26 * fConst0);
	fConst19 = (1.39650841721361e-13 + (fConst0 * ((fConst0 * (6.79263055101936e-16 + (fConst0 * (2.49956394010291e-17 + (fConst0 * (fConst18 - 5.62848079191661e-19)))))) - 6.32511620566482e-15)));
	fConst20 = (5.06350333062866e-26 * fConst0);
	fConst21 = (2.79301683442722e-13 + (fConst0 * ((fConst0 * ((fConst0 * (4.99912788020582e-17 + (fConst0 * (3.75232052794441e-19 - fConst20)))) - 1.35852611020387e-15)) - 4.21674413710988e-15)));
	fConst22 = (2.79301683442722e-13 + (fConst0 * (4.21674413710988e-15 + (fConst0 * ((fConst0 * ((fConst0 * (3.75232052794441e-19 + fConst20)) - 4.99912788020582e-17)) - 1.35852611020387e-15)))));
	fConst23 = (1.39650841721361e-13 + (fConst0 * (6.32511620566482e-15 + (fConst0 * (6.79263055101936e-16 + (fConst0 * ((fConst0 * (0 - (5.62848079191661e-19 + fConst18))) - 2.49956394010291e-17)))))));
	fConst24 = (1.0 / (2.79301683442722e-14 + (fConst0 * (2.10837206855494e-15 + (fConst0 * (6.79263055101936e-16 + (fConst0 * (2.49956394010291e-17 + (fConst0 * (1.8761602639722e-19 + fConst16))))))))));
	fConst25 = (1.91969658146125e-28 * fConst0);
	fConst26 = (1.85580923728473e-25 + fConst25);
	fConst27 = ((fConst0 * (1.28417029350963e-21 + (fConst0 * (2.96412666813708e-23 + (fConst0 * fConst26))))) - 5.56190530156167e-35);
	fConst28 = (2.34447194587753e-19 + (fConst0 * (3.78141066792101e-21 + (fConst0 * ((fConst0 * (0 - fConst26)) - 2.74055975769674e-24)))));
	fConst29 = (3.8393931629225e-26 * fConst0);
	fConst30 = ((fConst0 * ((fConst0 * ((fConst0 * (0 - (4.35717847353048e-23 + fConst29))) - 7.2517402922623e-21)) - 3.2657449261887e-19)) - 2.13208229658786e-19);
	fConst31 = (8.7797693860085e-29 * fConst0);
	fConst32 = (1.73769177200289e-25 + fConst31);
	fConst33 = ((fConst0 * (2.34447194587753e-19 + (fConst0 * (6.45410868622137e-21 + (fConst0 * (5.74453140263249e-23 + (fConst0 * fConst32))))))) - 1.01125550937485e-33);
	fConst34 = ((fConst0 * ((fConst0 * ((fConst0 * ((fConst0 * (0 - fConst32)) - 8.79647617632315e-23)) - 1.24168320637625e-20)) - 5.2738887295382e-19)) - 4.26416459317574e-19);
	fConst35 = (1.7559538772017e-26 * fConst0);
	fConst36 = (4.26416459317575e-19 + (fConst0 * ((fConst0 * ((fConst0 * (0 - (7.01275323109138e-24 + fConst35))) - 6.6938264041103e-22)) - 8.97810027051546e-21)));
	fConst37 = (7.25745997440848e-26 * fConst0);
	fConst38 = (3.68004528661724e-15 + (fConst0 * (7.98442414323855e-17 + (fConst0 * (4.80207616341231e-19 + (fConst0 * (4.83270952225433e-22 + fConst37)))))));
	fConst39 = (3.62872998720424e-28 * fConst0);
	fConst40 = (2.52344661631536e-24 + fConst39);
	fConst41 = (1.01125550937485e-29 + (fConst0 * ((fConst0 * ((fConst0 * ((fConst0 * ((fConst0 * (0 - fConst40)) - 2.18295349844616e-21)) - 3.53221173327878e-19)) - 1.60655994099041e-17)) - 2.15340311955366e-17)));
	fConst42 = (fConst0 * ((fConst0 * ((fConst0 * (8.46626752991924e-20 + (fConst0 * (2.18476286885277e-21 + (fConst0 * fConst40))))) - 3.4560962962513e-17)) - 2.32272470645234e-15));
	fConst43 = (1.10009314883802e-27 * fConst0);
	fConst44 = (fConst43 - 1.13378986041865e-24);
	fConst45 = (1.13378986041865e-24 - fConst43);
	fConst46 = (2.20018629767604e-25 * fConst0);
	fConst47 = (fConst46 - 4.29679382500905e-23);
	fConst48 = (3.46914825062448e-27 * fConst0);
	fConst49 = ((fConst0 * (3.73063872199228e-24 - fConst48)) - 2.2779375978716e-22);
	fConst50 = (4.58697571582143e-22 + (fConst0 * (fConst48 - 3.73063872199228e-24)));
	fConst51 = (6.93829650124896e-25 * fConst0);
	fConst52 = (4.14315081372073e-22 + (fConst0 * (3.95860002475e-22 - fConst51)));
	fConst53 = (1.20981023104306e-26 * fConst0);
	fConst54 = ((fConst0 * (2.16328174182473e-21 + fConst53)) - 4.03207370902736e-19);
	fConst55 = (6.0490511552153e-29 * fConst0);
	fConst56 = (1.08118680331922e-23 + fConst55);
	fConst57 = ((fConst0 * ((fConst0 * ((fConst0 * fConst56) - 1.11567278400556e-20)) - 2.09229116092896e-20)) - 9.82556839679967e-33);
	fConst58 = (9.82556839679967e-33 + (fConst0 * ((fConst0 * (1.11551728140517e-20 + (fConst0 * (0 - fConst56)))) - 2.25680752872163e-18)));
	fConst59 = ((fConst0 * ((fConst0 * (2.96412666813708e-23 + (fConst0 * (fConst25 - 1.85580923728473e-25)))) - 1.28417029350963e-21)) - 5.56190530156167e-35);
	fConst60 = (2.34447194587753e-19 + (fConst0 * ((fConst0 * ((fConst0 * (1.85580923728473e-25 - fConst25)) - 2.74055975769674e-24)) - 3.78141066792101e-21)));
	fConst61 = (2.13208229658786e-19 + (fConst0 * ((fConst0 * (7.2517402922623e-21 + (fConst0 * (fConst29 - 4.35717847353048e-23)))) - 3.2657449261887e-19)));
	fConst62 = (1.01125550937485e-33 + (fConst0 * (2.34447194587753e-19 + (fConst0 * ((fConst0 * (5.74453140263249e-23 + (fConst0 * (fConst31 - 1.73769177200289e-25)))) - 6.45410868622137e-21)))));
	fConst63 = (4.26416459317574e-19 + (fConst0 * ((fConst0 * (1.24168320637625e-20 + (fConst0 * ((fConst0 * (1.73769177200289e-25 - fConst31)) - 8.79647617632315e-23)))) - 5.2738887295382e-19)));
	fConst64 = ((fConst0 * ((fConst0 * (6.6938264041103e-22 + (fConst0 * (fConst35 - 7.01275323109138e-24)))) - 8.97810027051546e-21)) - 4.26416459317575e-19);
	fConst65 = ((fConst0 * (7.98442414323855e-17 + (fConst0 * ((fConst0 * (4.83270952225433e-22 - fConst37)) - 4.80207616341231e-19)))) - 3.68004528661724e-15);
	fConst66 = (1.01125550937485e-29 + (fConst0 * (2.15340311955366e-17 + (fConst0 * ((fConst0 * (3.53221173327878e-19 + (fConst0 * ((fConst0 * (2.52344661631536e-24 - fConst39)) - 2.18295349844616e-21)))) - 1.60655994099041e-17)))));
	fConst67 = (fConst0 * (2.32272470645234e-15 + (fConst0 * ((fConst0 * ((fConst0 * (2.18476286885277e-21 + (fConst0 * (fConst39 - 2.52344661631536e-24)))) - 8.46626752991924e-20)) - 3.4560962962513e-17))));
	fConst68 = (1.15181794887675e-27 * fConst0);
	fConst69 = ((fConst4 * ((fConst0 * (7.42323694913893e-25 - fConst68)) - 5.92825333627416e-23)) - 1.11238106031233e-34);
	fConst70 = (4.68894389175506e-19 + (fConst4 * (5.48111951539348e-24 + (fConst0 * (fConst68 - 7.42323694913893e-25)))));
	fConst71 = (1.535757265169e-25 * fConst0);
	fConst72 = (8.52832918635145e-19 + (fConst0 * ((fConst4 * (8.71435694706097e-23 - fConst71)) - 6.5314898523774e-19)));
	fConst73 = (5.2678616316051e-28 * fConst0);
	fConst74 = (4.0450220374994e-33 + (fConst0 * (4.68894389175505e-19 + (fConst4 * ((fConst0 * (6.95076708801156e-25 - fConst73)) - 1.1489062805265e-22)))));
	fConst75 = (1.70566583727029e-18 + (fConst0 * ((fConst4 * (1.75929523526463e-22 + (fConst0 * (fConst73 - 6.95076708801156e-25)))) - 1.05477774590764e-18)));
	fConst76 = (7.0238155088068e-26 * fConst0);
	fConst77 = ((fConst0 * ((fConst4 * (1.40255064621828e-23 - fConst76)) - 1.79562005410309e-20)) - 1.7056658372703e-18);
	fConst78 = (2.90298398976339e-25 * fConst0);
	fConst79 = ((fConst0 * (1.59688482864771e-16 + (fConst4 * (fConst78 - 9.66541904450867e-22)))) - 1.4720181146469e-14);
	fConst80 = (2.17723799232254e-27 * fConst0);
	fConst81 = (6.06753305624909e-29 + (fConst0 * (8.61361247821464e-17 + (fConst0 * ((fConst4 * (4.36590699689231e-21 + (fConst0 * (fConst80 - 1.00937864652614e-23)))) - 3.21311988198083e-17)))));
	fConst82 = (fConst0 * (9.29089882580934e-15 + (fConst0 * ((fConst4 * ((fConst0 * (1.00937864652614e-23 - fConst80)) - 4.36952573770555e-21)) - 6.91219259250261e-17))));
	fConst83 = (2.87954487219187e-27 * fConst0);
	fConst84 = (5.56190530156167e-35 + (fConst0 * (3.85251088052888e-21 + (fConst0 * ((fConst0 * (fConst83 - 9.27904618642366e-25)) - 2.96412666813708e-23)))));
	fConst85 = ((fConst0 * (1.1344232003763e-20 + (fConst0 * (2.74055975769674e-24 + (fConst0 * (9.27904618642366e-25 - fConst83)))))) - 2.34447194587753e-19);
	fConst86 = (1.91969658146125e-25 * fConst0);
	fConst87 = (1.06604114829393e-18 + (fConst0 * (3.2657449261887e-19 + (fConst0 * ((fConst0 * (4.35717847353048e-23 + fConst86)) - 2.17552208767869e-20)))));
	fConst88 = (1.31696540790127e-27 * fConst0);
	fConst89 = (5.05627754687424e-33 + (fConst0 * ((fConst0 * (1.93623260586641e-20 + (fConst0 * ((fConst0 * (fConst88 - 8.68845886001445e-25)) - 5.74453140263249e-23)))) - 2.34447194587753e-19)));
	fConst90 = (2.13208229658787e-18 + (fConst0 * (5.2738887295382e-19 + (fConst0 * ((fConst0 * (8.79647617632315e-23 + (fConst0 * (8.68845886001445e-25 - fConst88)))) - 3.72504961912875e-20)))));
	fConst91 = (8.7797693860085e-26 * fConst0);
	fConst92 = ((fConst0 * (8.97810027051546e-21 + (fConst0 * ((fConst0 * (7.01275323109138e-24 + fConst91)) - 2.00814792123309e-21)))) - 2.13208229658787e-18);
	fConst93 = (3.62872998720424e-25 * fConst0);
	fConst94 = ((fConst0 * ((fConst0 * (1.44062284902369e-18 + (fConst0 * (0 - (4.83270952225433e-22 + fConst93))))) - 7.98442414323855e-17)) - 1.84002264330862e-14);
	fConst95 = (5.44309498080636e-27 * fConst0);
	fConst96 = (1.51688326406227e-28 + (fConst0 * (1.07670155977683e-16 + (fConst0 * (1.60655994099041e-17 + (fConst0 * ((fConst0 * (2.18295349844616e-21 + (fConst0 * (1.26172330815768e-23 - fConst95)))) - 1.05966351998363e-18)))))));
	fConst97 = (fConst0 * (1.16136235322617e-14 + (fConst0 * (3.4560962962513e-17 + (fConst0 * (2.53988025897577e-19 + (fConst0 * ((fConst0 * (fConst95 - 1.26172330815768e-23)) - 2.18476286885277e-21))))))));
	fConst98 = (3.8393931629225e-27 * fConst4);
	fConst99 = (2.22476212062467e-34 + (fConst4 * (1.18565066725483e-22 - fConst98)));
	fConst100 = ((fConst4 * (fConst98 - 1.0962239030787e-23)) - 9.37788778351013e-19);
	fConst101 = (1.30629797047548e-18 - (1.74287138941219e-22 * fConst4));
	fConst102 = (1.7559538772017e-27 * fConst4);
	fConst103 = ((fConst4 * (2.297812561053e-22 - fConst102)) - 9.37788778351011e-19);
	fConst104 = (2.10955549181528e-18 + (fConst4 * (fConst102 - 3.51859047052926e-22)));
	fConst105 = (3.59124010820619e-20 - (2.80510129243655e-23 * fConst4));
	fConst106 = ((1.93308380890173e-21 * fConst4) - 3.19376965729542e-16);
	fConst107 = (7.25745997440848e-27 * fConst4);
	fConst108 = (2.0225110187497e-28 + (fConst4 * (6.42623976396166e-17 + (fConst4 * (fConst107 - 8.73181399378463e-21)))));
	fConst109 = (fConst4 * (1.38243851850052e-16 + (fConst4 * (8.73905147541109e-21 - fConst107))));
	fConst110 = (9.27904618642366e-25 + fConst83);
	fConst111 = (5.56190530156167e-35 + (fConst0 * ((fConst0 * ((fConst0 * fConst110) - 2.96412666813708e-23)) - 3.85251088052888e-21)));
	fConst112 = ((fConst0 * ((fConst0 * (2.74055975769674e-24 + (fConst0 * (0 - fConst110)))) - 1.1344232003763e-20)) - 2.34447194587753e-19);
	fConst113 = ((fConst0 * (3.2657449261887e-19 + (fConst0 * (2.17552208767869e-20 + (fConst0 * (4.35717847353048e-23 - fConst86)))))) - 1.06604114829393e-18);
	fConst114 = (8.68845886001445e-25 + fConst88);
	fConst115 = ((fConst0 * ((fConst0 * ((fConst0 * ((fConst0 * fConst114) - 5.74453140263249e-23)) - 1.93623260586641e-20)) - 2.34447194587753e-19)) - 5.05627754687424e-33);
	fConst116 = ((fConst0 * (5.2738887295382e-19 + (fConst0 * (3.72504961912875e-20 + (fConst0 * (8.79647617632315e-23 + (fConst0 * (0 - fConst114)))))))) - 2.13208229658787e-18);
	fConst117 = (2.13208229658787e-18 + (fConst0 * (8.97810027051546e-21 + (fConst0 * (2.00814792123309e-21 + (fConst0 * (7.01275323109138e-24 - fConst91)))))));
	fConst118 = (1.84002264330862e-14 + (fConst0 * ((fConst0 * ((fConst0 * (fConst93 - 4.83270952225433e-22)) - 1.44062284902369e-18)) - 7.98442414323855e-17)));
	fConst119 = (1.26172330815768e-23 + fConst95);
	fConst120 = (1.51688326406227e-28 + (fConst0 * ((fConst0 * (1.60655994099041e-17 + (fConst0 * (1.05966351998363e-18 + (fConst0 * (2.18295349844616e-21 + (fConst0 * (0 - fConst119)))))))) - 1.07670155977683e-16)));
	fConst121 = (fConst0 * ((fConst0 * (3.4560962962513e-17 + (fConst0 * ((fConst0 * ((fConst0 * fConst119) - 2.18476286885277e-21)) - 2.53988025897577e-19)))) - 1.16136235322617e-14));
	fConst122 = (7.42323694913893e-25 + fConst68);
	fConst123 = ((fConst4 * ((fConst0 * (0 - fConst122)) - 5.92825333627416e-23)) - 1.11238106031233e-34);
	fConst124 = (4.68894389175506e-19 + (fConst4 * (5.48111951539348e-24 + (fConst0 * fConst122))));
	fConst125 = ((fConst0 * ((fConst4 * (8.71435694706097e-23 + fConst71)) - 6.5314898523774e-19)) - 8.52832918635145e-19);
	fConst126 = (6.95076708801156e-25 + fConst73);
	fConst127 = ((fConst0 * (4.68894389175505e-19 + (fConst4 * ((fConst0 * (0 - fConst126)) - 1.1489062805265e-22)))) - 4.0450220374994e-33);
	fConst128 = ((fConst0 * ((fConst4 * (1.75929523526463e-22 + (fConst0 * fConst126))) - 1.05477774590764e-18)) - 1.70566583727029e-18);
	fConst129 = (1.7056658372703e-18 + (fConst0 * ((fConst4 * (1.40255064621828e-23 + fConst76)) - 1.79562005410309e-20)));
	fConst130 = (1.4720181146469e-14 + (fConst0 * (1.59688482864771e-16 + (fConst4 * (0 - (9.66541904450867e-22 + fConst78))))));
	fConst131 = (1.00937864652614e-23 + fConst80);
	fConst132 = (6.06753305624909e-29 + (fConst0 * ((fConst0 * ((fConst4 * (4.36590699689231e-21 + (fConst0 * fConst131))) - 3.21311988198083e-17)) - 8.61361247821464e-17)));
	fConst133 = (fConst0 * ((fConst0 * ((fConst4 * ((fConst0 * (0 - fConst131)) - 4.36952573770555e-21)) - 6.91219259250261e-17)) - 9.29089882580934e-15));
	fConst134 = (6.60055889302811e-27 * fConst0);
	fConst135 = (4.53515944167461e-24 - fConst134);
	fConst136 = (fConst134 - 4.53515944167461e-24);
	fConst137 = (8.80074519070414e-25 * fConst0);
	fConst138 = (8.59358765001811e-23 - fConst137);
	fConst139 = (2.08148895037469e-26 * fConst0);
	fConst140 = (4.5558751957432e-22 + (fConst0 * (fConst139 - 1.49225548879691e-23)));
	fConst141 = ((fConst0 * (1.49225548879691e-23 - fConst139)) - 9.17395143164286e-22);
	fConst142 = (2.77531860049959e-24 * fConst0);
	fConst143 = (fConst142 - 7.9172000495e-22);
	fConst144 = (4.83924092417224e-26 * fConst0);
	fConst145 = (0 - (4.32656348364945e-21 + fConst144));
	fConst146 = (3.62943069312918e-28 * fConst0);
	fConst147 = (4.32474721327688e-23 + fConst146);
	fConst148 = ((fConst4 * (2.23134556801112e-20 + (fConst0 * (0 - fConst147)))) - 1.96511367935993e-32);
	fConst149 = (1.96511367935993e-32 + (fConst4 * ((fConst0 * fConst147) - 2.23103456281034e-20)));
	fConst150 = (1.65013972325703e-26 * fConst0);
	fConst151 = (fConst150 - 5.66894930209326e-24);
	fConst152 = (5.66894930209326e-24 - fConst150);
	fConst153 = (1.10009314883802e-24 * fConst0);
	fConst154 = (4.29679382500905e-23 + fConst153);
	fConst155 = (5.20372237593672e-26 * fConst0);
	fConst156 = (2.2779375978716e-22 + (fConst0 * (1.86531936099614e-23 - fConst155)));
	fConst157 = ((fConst0 * (fConst155 - 1.86531936099614e-23)) - 4.58697571582143e-22);
	fConst158 = (3.46914825062448e-24 * fConst0);
	fConst159 = ((fConst0 * (0 - (3.95860002475e-22 + fConst158))) - 1.24294524411622e-21);
	fConst160 = (6.0490511552153e-26 * fConst0);
	fConst161 = (1.20962211270821e-18 + (fConst0 * (fConst160 - 2.16328174182473e-21)));
	fConst162 = (9.07357673282294e-28 * fConst0);
	fConst163 = (5.4059340165961e-23 + fConst162);
	fConst164 = (9.82556839679967e-33 + (fConst0 * (6.27687348278688e-20 + (fConst0 * (1.11567278400556e-20 + (fConst0 * fConst163))))));
	fConst165 = ((fConst0 * (6.77042258616489e-18 + (fConst0 * ((fConst0 * (0 - fConst163)) - 1.11551728140517e-20)))) - 9.82556839679967e-33);
	fConst166 = (6.93829650124896e-26 * fConst4);
	fConst167 = (fConst166 - 9.1117503914864e-22);
	fConst168 = (1.83479028632857e-21 - fConst166);
	fConst169 = (1.20981023104306e-27 * fConst4);
	fConst170 = (3.93022735871987e-32 + (fConst4 * (0 - (4.46269113602224e-20 + fConst169))));
	fConst171 = ((fConst4 * (4.46206912562068e-20 + fConst169)) - 3.93022735871987e-32);
	fConst172 = (5.66894930209326e-24 + fConst150);
	fConst173 = (0 - fConst172);
	fConst174 = (4.29679382500905e-23 - fConst153);
	fConst175 = (1.86531936099614e-23 + fConst155);
	fConst176 = (2.2779375978716e-22 + (fConst0 * (0 - fConst175)));
	fConst177 = ((fConst0 * fConst175) - 4.58697571582143e-22);
	fConst178 = (1.24294524411622e-21 + (fConst0 * (fConst158 - 3.95860002475e-22)));
	fConst179 = ((fConst0 * (0 - (2.16328174182473e-21 + fConst160))) - 1.20962211270821e-18);
	fConst180 = (9.82556839679967e-33 + (fConst0 * ((fConst0 * (1.11567278400556e-20 + (fConst0 * (fConst162 - 5.4059340165961e-23)))) - 6.27687348278688e-20)));
	fConst181 = ((fConst0 * ((fConst0 * ((fConst0 * (5.4059340165961e-23 - fConst162)) - 1.11551728140517e-20)) - 6.77042258616489e-18)) - 9.82556839679967e-33);
	fConst182 = (7.9172000495e-22 + fConst142);
	fConst183 = (4.53515944167461e-24 + fConst134);
	fConst184 = (0 - fConst183);
	fConst185 = (8.59358765001811e-23 + fConst137);
	fConst186 = (1.49225548879691e-23 + fConst139);
	fConst187 = (4.5558751957432e-22 + (fConst0 * fConst186));
	fConst188 = ((fConst0 * (0 - fConst186)) - 9.17395143164286e-22);
	fConst189 = (fConst144 - 4.32656348364945e-21);
	fConst190 = ((fConst4 * (2.23134556801112e-20 + (fConst0 * (4.32474721327688e-23 - fConst146)))) - 1.96511367935993e-32);
	fConst191 = (1.96511367935993e-32 + (fConst4 * ((fConst0 * (fConst146 - 4.32474721327688e-23)) - 2.23103456281034e-20)));
	fConst192 = (1.13378986041865e-24 + fConst43);
	fConst193 = (0 - fConst192);
	fConst194 = (0 - (4.29679382500905e-23 + fConst46));
	fConst195 = (3.73063872199228e-24 + fConst48);
	fConst196 = ((fConst0 * (0 - fConst195)) - 2.2779375978716e-22);
	fConst197 = (4.58697571582143e-22 + (fConst0 * fConst195));
	fConst198 = ((fConst0 * (3.95860002475e-22 + fConst51)) - 4.14315081372073e-22);
	fConst199 = (4.03207370902736e-19 + (fConst0 * (2.16328174182473e-21 - fConst53)));
	fConst200 = ((fConst0 * (2.09229116092896e-20 + (fConst0 * ((fConst0 * (fConst55 - 1.08118680331922e-23)) - 1.11567278400556e-20)))) - 9.82556839679967e-33);
	fConst201 = (9.82556839679967e-33 + (fConst0 * (2.25680752872163e-18 + (fConst0 * (1.11551728140517e-20 + (fConst0 * (1.08118680331922e-23 - fConst55)))))));
	fConst202 = (2.21477376705373e-26 * fConst0);
	fConst203 = (2.21955383001753e-15 + (fConst0 * ((fConst0 * (2.76366301878458e-15 + (fConst0 * ((fConst0 * (8.20289496102011e-19 - fConst202)) - 1.07989398172671e-16)))) - 1.68022586665771e-16)));
	fConst204 = (1.10738688352687e-25 * fConst0);
	fConst205 = (1.10977691500877e-14 + (fConst0 * ((fConst0 * (2.76366301878458e-15 + (fConst0 * (1.07989398172671e-16 + (fConst0 * (fConst204 - 2.46086848830603e-18)))))) - 5.04067759997312e-16)));
	fConst206 = (2.21477376705373e-25 * fConst0);
	fConst207 = (2.21955383001753e-14 + (fConst0 * ((fConst0 * ((fConst0 * (2.15978796345342e-16 + (fConst0 * (1.64057899220402e-18 - fConst206)))) - 5.52732603756917e-15)) - 3.36045173331541e-16)));
	fConst208 = (2.21955383001753e-14 + (fConst0 * (3.36045173331541e-16 + (fConst0 * ((fConst0 * ((fConst0 * (1.64057899220402e-18 + fConst206)) - 2.15978796345342e-16)) - 5.52732603756917e-15)))));
	fConst209 = (1.10977691500877e-14 + (fConst0 * (5.04067759997312e-16 + (fConst0 * (2.76366301878458e-15 + (fConst0 * ((fConst0 * (0 - (2.46086848830603e-18 + fConst204))) - 1.07989398172671e-16)))))));
	fConst210 = (2.21955383001753e-15 + (fConst0 * (1.68022586665771e-16 + (fConst0 * (2.76366301878458e-15 + (fConst0 * (1.07989398172671e-16 + (fConst0 * (8.20289496102011e-19 + fConst202)))))))));
	fConst211 = (3.22912277501057e-21 * fConst0);
	fConst212 = (2.78116542918484e-14 + (fConst0 * (fConst211 - 6.38442519444497e-17)));
	fConst213 = (1.27688503888899e-16 * fConst0);
	fConst214 = (1.11246617167394e-13 - fConst213);
	fConst215 = (1.29164911000423e-20 * fConst0);
	fConst216 = (1.11246617167394e-13 + (fConst0 * (1.27688503888899e-16 - fConst215)));
	fConst217 = (3.83065511666698e-16 * fConst0);
	fConst218 = (fConst217 - 1.11246617167394e-13);
	fConst219 = ((1.93747366500634e-20 * fConst4) - 2.78116542918484e-13);
	fConst220 = (0 - (1.11246617167394e-13 + fConst217));
	fConst221 = (1.11246617167394e-13 + (fConst0 * (0 - (1.27688503888899e-16 + fConst215))));
	fConst222 = (1.11246617167394e-13 + fConst213);
	fConst223 = (2.78116542918484e-14 + (fConst0 * (6.38442519444497e-17 + fConst211)));
	fConst224 = (fConst4 / fConst14);
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
	double 	fSlow1 = (0.007000000000000006 * double(fslider1));
	double 	fSlow2 = (0.00036676987543879196 * (exp((3 * double(fslider2))) - 1));
	for (int i=0; i<count; i++) {
		fRec2[0] = (fSlow0 + (0.993 * fRec2[1]));
		fRec3[0] = (fSlow1 + (0.993 * fRec3[1]));
		double fTemp0 = (5.11699751181088e-15 + ((fRec2[0] * (fConst42 + (fConst41 * fRec2[0]))) + (fConst0 * (fConst38 + (fRec3[0] * (fConst36 + ((fRec2[0] * (fConst34 + (fConst33 * fRec2[0]))) + (fRec3[0] * (fConst30 + (fRec2[0] * ((fConst0 * (fConst28 + (fConst27 * fRec2[0]))) - 1.01125550937485e-33)))))))))));
		fRec5[0] = (fSlow2 + (0.993 * fRec5[1]));
		double fTemp1 = (4.73570824768576e-05 * fRec5[0]);
		double fTemp2 = (0.00103238439799549 + (fConst0 * (7.78862764390594e-06 + (fRec5[0] * (4.97249366007004e-05 - fTemp1)))));
		double fTemp3 = (1.2022682288553e-06 + (6.01134114427651e-05 * fRec5[0]));
		fRec6[0] = ((double)input0[i] - ((fRec6[1] * (0.00103238439799549 + (fConst0 * ((fRec5[0] * (fTemp1 - 4.97249366007004e-05)) - 7.78862764390594e-06)))) / fTemp2));
		fRec4[0] = ((fConst0 * (((fRec6[1] * fTemp3) + (fRec6[0] * (0 - fTemp3))) / fTemp2)) - (((((((fRec4[1] * (3.07019850708653e-14 + ((fRec2[0] * (fConst133 + (fConst132 * fRec2[0]))) + (fConst0 * (fConst130 + (fRec3[0] * (fConst129 + ((fRec2[0] * (fConst128 + (fConst127 * fRec2[0]))) + (fRec3[0] * (fConst125 + (fRec2[0] * ((fConst0 * (fConst124 + (fConst123 * fRec2[0]))) - 4.0450220374994e-33)))))))))))) + (fRec4[2] * (7.67549626771633e-14 + ((fRec2[0] * (fConst121 + (fConst120 * fRec2[0]))) + (fConst0 * (fConst118 + (fRec3[0] * (fConst117 + ((fRec2[0] * (fConst116 + (fConst115 * fRec2[0]))) + (fRec3[0] * (fConst113 + (fRec2[0] * ((fConst0 * (fConst112 + (fConst111 * fRec2[0]))) - 5.05627754687424e-33))))))))))))) + (fRec4[3] * (1.02339950236218e-13 + ((fRec2[0] * (fConst109 + (fConst108 * fRec2[0]))) + (fConst4 * (fConst106 + (fRec3[0] * (fConst105 + ((fRec2[0] * (fConst104 + (fConst103 * fRec2[0]))) + (fRec3[0] * (fConst101 + (fRec2[0] * (fConst100 + (fConst99 * fRec2[0])))))))))))))) + (fRec4[4] * (7.67549626771633e-14 + ((fRec2[0] * (fConst97 + (fConst96 * fRec2[0]))) + (fConst0 * (fConst94 + (fRec3[0] * (fConst92 + ((fRec2[0] * (fConst90 + (fConst89 * fRec2[0]))) + (fRec3[0] * (fConst87 + (fRec2[0] * (5.05627754687424e-33 + (fConst0 * (fConst85 + (fConst84 * fRec2[0])))))))))))))))) + (fRec4[5] * (3.07019850708653e-14 + ((fRec2[0] * (fConst82 + (fConst81 * fRec2[0]))) + (fConst0 * (fConst79 + (fRec3[0] * (fConst77 + ((fRec2[0] * (fConst75 + (fConst74 * fRec2[0]))) + (fRec3[0] * (fConst72 + (fRec2[0] * (4.0450220374994e-33 + (fConst0 * (fConst70 + (fConst69 * fRec2[0])))))))))))))))) + (fRec4[6] * (5.11699751181088e-15 + ((fRec2[0] * (fConst67 + (fConst66 * fRec2[0]))) + (fConst0 * (fConst65 + (fRec3[0] * (fConst64 + ((fRec2[0] * (fConst63 + (fConst62 * fRec2[0]))) + (fRec3[0] * (fConst61 + (fRec2[0] * (1.01125550937485e-33 + (fConst0 * (fConst60 + (fConst59 * fRec2[0])))))))))))))))) / fTemp0));
		fRec1[0] = ((fConst4 * ((((((((fRec4[0] * (((fRec2[0] * (fConst201 + (fConst200 * fRec2[0]))) + (fConst0 * (fConst199 + (fRec3[0] * (fConst198 + ((fRec2[0] * (4.14315081372074e-22 + (fConst0 * (fConst197 + (fConst196 * fRec2[0]))))) + (fRec3[0] * (2.07157540686037e-22 + (fConst0 * (fConst194 + (fRec2[0] * ((fConst0 * (fConst193 + (fConst192 * fRec2[0]))) - 2.27793759787161e-22)))))))))))) - 4.97178097646487e-18)) + (fRec4[1] * (((fRec2[0] * (fConst191 + (fConst190 * fRec2[0]))) + (fConst4 * (fConst189 + (fRec3[0] * (((fRec2[0] * (fConst188 + (fConst187 * fRec2[0]))) + (fRec3[0] * (fConst185 + (fRec2[0] * (4.55587519574321e-22 + (fConst0 * (fConst183 + (fConst184 * fRec2[0])))))))) - fConst182))))) - 9.94356195292975e-18))) + (fRec4[2] * (4.97178097646487e-18 + ((fRec2[0] * (fConst181 + (fConst180 * fRec2[0]))) + (fConst0 * (fConst179 + (fRec3[0] * (fConst178 + ((fRec2[0] * ((fConst0 * (fConst177 + (fConst176 * fRec2[0]))) - 1.24294524411622e-21)) + (fRec3[0] * ((fConst0 * (fConst174 + (fRec2[0] * (2.27793759787161e-22 + (fConst0 * (fConst173 + (fConst172 * fRec2[0]))))))) - 6.21472622058109e-22))))))))))) + (fRec4[3] * (1.98871239058595e-17 + ((fRec2[0] * (fConst171 + (fConst170 * fRec2[0]))) + (fConst4 * (8.6531269672989e-21 + (fRec3[0] * (1.5834400099e-21 + ((fRec2[0] * (fConst168 + (fConst167 * fRec2[0]))) + (fRec3[0] * ((fRec2[0] * ((fConst4 * (2.20018629767604e-26 + (0 - (2.20018629767604e-26 * fRec2[0])))) - 9.11175039148642e-22)) - 1.71871753000362e-22))))))))))) + (fRec4[4] * (4.97178097646487e-18 + ((fRec2[0] * (fConst165 + (fConst164 * fRec2[0]))) + (fConst0 * (fConst161 + (fRec3[0] * (fConst159 + ((fRec2[0] * (1.24294524411622e-21 + (fConst0 * (fConst157 + (fConst156 * fRec2[0]))))) + (fRec3[0] * (6.21472622058109e-22 + (fConst0 * (fConst154 + (fRec2[0] * (2.27793759787161e-22 + (fConst0 * (fConst152 + (fConst151 * fRec2[0])))))))))))))))))) + (fRec4[5] * (((fRec2[0] * (fConst149 + (fConst148 * fRec2[0]))) + (fConst4 * (fConst145 + (fRec3[0] * (fConst143 + ((fRec2[0] * (fConst141 + (fConst140 * fRec2[0]))) + (fRec3[0] * (fConst138 + (fRec2[0] * (4.55587519574321e-22 + (fConst0 * (fConst136 + (fConst135 * fRec2[0]))))))))))))) - 9.94356195292975e-18))) + (fRec4[6] * (((fRec2[0] * (fConst58 + (fConst57 * fRec2[0]))) + (fConst0 * (fConst54 + (fRec3[0] * (fConst52 + ((fRec2[0] * ((fConst0 * (fConst50 + (fConst49 * fRec2[0]))) - 4.14315081372074e-22)) + (fRec3[0] * ((fConst0 * (fConst47 + (fRec2[0] * ((fConst0 * (fConst45 + (fConst44 * fRec2[0]))) - 2.27793759787161e-22)))) - 2.07157540686037e-22)))))))) - 4.97178097646487e-18))) / fTemp0)) - (fConst24 * (((((fConst23 * fRec1[1]) + (fConst22 * fRec1[2])) + (fConst21 * fRec1[3])) + (fConst19 * fRec1[4])) + (fConst17 * fRec1[5]))));
		fRec0[0] = (supersonicclip((fConst24 * ((((((fConst210 * fRec1[0]) + (fConst209 * fRec1[1])) + (fConst208 * fRec1[2])) + (fConst207 * fRec1[3])) + (fConst205 * fRec1[4])) + (fConst203 * fRec1[5])))) - (fConst15 * ((((((((fConst13 * fRec0[1]) + (fConst12 * fRec0[2])) + (fConst11 * fRec0[3])) + (fConst10 * fRec0[4])) + (fConst9 * fRec0[5])) + (fConst7 * fRec0[6])) + (fConst5 * fRec0[7])) + (fConst2 * fRec0[8]))));
		output0[i] = (FAUSTFLOAT)(fConst224 * (((((((((fConst223 * fRec0[0]) + (fConst222 * fRec0[1])) + (fConst221 * fRec0[2])) + (fConst220 * fRec0[3])) + (fConst219 * fRec0[4])) + (fConst218 * fRec0[5])) + (fConst216 * fRec0[6])) + (fConst214 * fRec0[7])) + (fConst212 * fRec0[8])));
		// post processing
		for (int i=8; i>0; i--) fRec0[i] = fRec0[i-1];
		for (int i=5; i>0; i--) fRec1[i] = fRec1[i-1];
		for (int i=6; i>0; i--) fRec4[i] = fRec4[i-1];
		fRec6[1] = fRec6[0];
		fRec5[1] = fRec5[0];
		fRec3[1] = fRec3[0];
		fRec2[1] = fRec2[0];
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
	case BASS: 
		fslider0_ = (float*)data; // , 0.5, 0.0, 1.0, 0.01 
		break;
	case TREBLE: 
		fslider1_ = (float*)data; // , 0.5, 0.0, 1.0, 0.01 
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
   BASS, 
   TREBLE, 
   VOLUME, 
} PortIndex;
*/

} // end namespace supersonic
