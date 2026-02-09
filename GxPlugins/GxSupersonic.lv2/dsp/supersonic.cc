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
	FAUSTFLOAT 	fslider0;
	FAUSTFLOAT	*fslider0_;
	double 	fRec1[2];
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
	double 	fConst29;
	double 	fConst30;
	double 	fConst31;
	double 	fConst32;
	double 	fConst33;
	FAUSTFLOAT 	fslider1;
	FAUSTFLOAT	*fslider1_;
	double 	fRec4[2];
	double 	fConst34;
	double 	fConst35;
	double 	fConst36;
	double 	fConst37;
	double 	fConst38;
	double 	fConst39;
	FAUSTFLOAT 	fslider2;
	FAUSTFLOAT	*fslider2_;
	double 	fRec5[2];
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
	double 	fConst134;
	double 	fConst135;
	double 	fConst136;
	double 	fConst137;
	double 	fConst138;
	double 	fConst139;
	double 	fConst140;
	double 	fConst141;
	double 	fConst142;
	FAUSTFLOAT 	fslider3;
	FAUSTFLOAT	*fslider3_;
	double 	fRec7[2];
	double 	fRec8[2];
	double 	fRec6[7];
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
	double 	fConst202;
	double 	fConst203;
	double 	fConst204;
	double 	fConst205;
	double 	fConst206;
	double 	fConst207;
	double 	fConst208;
	double 	fConst209;
	double 	fConst210;
	double 	fRec3[6];
	double 	fConst211;
	double 	fConst212;
	double 	fConst213;
	double 	fConst214;
	double 	fConst215;
	double 	fConst216;
	double 	fConst217;
	double 	fConst218;
	double 	fConst219;
	double 	fRec2[2];
	double 	fRec0[9];
	double 	fConst220;
	double 	fConst221;
	double 	fConst222;
	double 	fConst223;
	double 	fConst224;
	double 	fConst225;
	double 	fConst226;
	double 	fConst227;
	double 	fConst228;
	double 	fConst229;
	double 	fConst230;
	double 	fConst231;
	double 	fConst232;
	double 	fConst233;

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
	for (int i=0; i<2; i++) fRec1[i] = 0;
	for (int i=0; i<2; i++) fRec4[i] = 0;
	for (int i=0; i<2; i++) fRec5[i] = 0;
	for (int i=0; i<2; i++) fRec7[i] = 0;
	for (int i=0; i<2; i++) fRec8[i] = 0;
	for (int i=0; i<7; i++) fRec6[i] = 0;
	for (int i=0; i<6; i++) fRec3[i] = 0;
	for (int i=0; i<2; i++) fRec2[i] = 0;
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
	fConst16 = (2.24914085283282e-06 * fConst0);
	fConst17 = (0 - (0.112461932029384 + fConst16));
	fConst18 = (2.6891901501262e-06 * fConst0);
	fConst19 = (fConst18 - 0.99009478393055);
	fConst20 = (2.91410423540948e-07 * fConst0);
	fConst21 = (1.47162430127362 + fConst20);
	fConst22 = (0.99009478393055 + fConst18);
	fConst23 = (fConst16 - 0.112461932029384);
	fConst24 = (1.47162430127362 - fConst20);
	fConst25 = (5.06350333062866e-27 * fConst0);
	fConst26 = (2.7930168344274e-14 + (fConst0 * ((fConst0 * (6.79263055101807e-16 + (fConst0 * ((fConst0 * (1.87616026397221e-19 - fConst25)) - 2.49956394010259e-17)))) - 2.10837206855448e-15)));
	fConst27 = (2.53175166531433e-26 * fConst0);
	fConst28 = (1.3965084172137e-13 + (fConst0 * ((fConst0 * (6.79263055101807e-16 + (fConst0 * (2.49956394010259e-17 + (fConst0 * (fConst27 - 5.62848079191662e-19)))))) - 6.32511620566344e-15)));
	fConst29 = (5.06350333062866e-26 * fConst0);
	fConst30 = (2.7930168344274e-13 + (fConst0 * ((fConst0 * ((fConst0 * (4.99912788020519e-17 + (fConst0 * (3.75232052794441e-19 - fConst29)))) - 1.35852611020361e-15)) - 4.21674413710896e-15)));
	fConst31 = (2.7930168344274e-13 + (fConst0 * (4.21674413710896e-15 + (fConst0 * ((fConst0 * ((fConst0 * (3.75232052794441e-19 + fConst29)) - 4.99912788020519e-17)) - 1.35852611020361e-15)))));
	fConst32 = (1.3965084172137e-13 + (fConst0 * (6.32511620566344e-15 + (fConst0 * (6.79263055101807e-16 + (fConst0 * ((fConst0 * (0 - (5.62848079191662e-19 + fConst27))) - 2.49956394010259e-17)))))));
	fConst33 = (1.0 / (2.7930168344274e-14 + (fConst0 * (2.10837206855448e-15 + (fConst0 * (6.79263055101807e-16 + (fConst0 * (2.49956394010259e-17 + (fConst0 * (1.87616026397221e-19 + fConst25))))))))));
	fConst34 = (1.91969658146125e-28 * fConst0);
	fConst35 = (1.85580923728473e-25 + fConst34);
	fConst36 = ((fConst0 * (1.28417029350963e-21 + (fConst0 * (2.96412666813708e-23 + (fConst0 * fConst35))))) - 5.56190530156167e-35);
	fConst37 = (2.34447194587753e-19 + (fConst0 * (3.78141066792101e-21 + (fConst0 * ((fConst0 * (0 - fConst35)) - 2.74055975769674e-24)))));
	fConst38 = (3.8393931629225e-26 * fConst0);
	fConst39 = ((fConst0 * ((fConst0 * ((fConst0 * (0 - (4.35717847353048e-23 + fConst38))) - 7.2517402922623e-21)) - 3.2657449261887e-19)) - 2.13208229658786e-19);
	fConst40 = (8.7797693860085e-29 * fConst0);
	fConst41 = (1.73769177200289e-25 + fConst40);
	fConst42 = ((fConst0 * (2.34447194587753e-19 + (fConst0 * (6.45410868622137e-21 + (fConst0 * (5.74453140263249e-23 + (fConst0 * fConst41))))))) - 1.01125550937485e-33);
	fConst43 = ((fConst0 * ((fConst0 * ((fConst0 * ((fConst0 * (0 - fConst41)) - 8.79647617632315e-23)) - 1.24168320637625e-20)) - 5.2738887295382e-19)) - 4.26416459317574e-19);
	fConst44 = (1.7559538772017e-26 * fConst0);
	fConst45 = (4.26416459317575e-19 + (fConst0 * ((fConst0 * ((fConst0 * (0 - (7.01275323109138e-24 + fConst44))) - 6.6938264041103e-22)) - 8.97810027051546e-21)));
	fConst46 = (7.25745997440848e-26 * fConst0);
	fConst47 = (3.68004528661724e-15 + (fConst0 * (7.98442414323855e-17 + (fConst0 * (4.80207616341231e-19 + (fConst0 * (4.83270952225433e-22 + fConst46)))))));
	fConst48 = (3.62872998720424e-28 * fConst0);
	fConst49 = (2.52344661631536e-24 + fConst48);
	fConst50 = (1.01125550937485e-29 + (fConst0 * ((fConst0 * ((fConst0 * ((fConst0 * ((fConst0 * (0 - fConst49)) - 2.18295349844616e-21)) - 3.53221173327878e-19)) - 1.60655994099041e-17)) - 2.15340311955366e-17)));
	fConst51 = (fConst0 * ((fConst0 * ((fConst0 * (8.46626752991924e-20 + (fConst0 * (2.18476286885277e-21 + (fConst0 * fConst49))))) - 3.4560962962513e-17)) - 2.32272470645234e-15));
	fConst52 = (1.10009314883802e-27 * fConst0);
	fConst53 = (fConst52 - 1.13378986041865e-24);
	fConst54 = (1.13378986041865e-24 - fConst52);
	fConst55 = (2.20018629767604e-25 * fConst0);
	fConst56 = (fConst55 - 4.29679382500905e-23);
	fConst57 = (3.46914825062448e-27 * fConst0);
	fConst58 = ((fConst0 * (3.73063872199228e-24 - fConst57)) - 2.2779375978716e-22);
	fConst59 = (4.58697571582143e-22 + (fConst0 * (fConst57 - 3.73063872199228e-24)));
	fConst60 = (6.93829650124896e-25 * fConst0);
	fConst61 = (4.14315081372073e-22 + (fConst0 * (3.95860002475e-22 - fConst60)));
	fConst62 = (1.20981023104306e-26 * fConst0);
	fConst63 = ((fConst0 * (2.16328174182473e-21 + fConst62)) - 4.03207370902736e-19);
	fConst64 = (6.0490511552153e-29 * fConst0);
	fConst65 = (1.08118680331922e-23 + fConst64);
	fConst66 = ((fConst0 * ((fConst0 * ((fConst0 * fConst65) - 1.11567278400556e-20)) - 2.09229116092896e-20)) - 9.82556839679967e-33);
	fConst67 = (9.82556839679967e-33 + (fConst0 * ((fConst0 * (1.11551728140517e-20 + (fConst0 * (0 - fConst65)))) - 2.25680752872163e-18)));
	fConst68 = ((fConst0 * ((fConst0 * (2.96412666813708e-23 + (fConst0 * (fConst34 - 1.85580923728473e-25)))) - 1.28417029350963e-21)) - 5.56190530156167e-35);
	fConst69 = (2.34447194587753e-19 + (fConst0 * ((fConst0 * ((fConst0 * (1.85580923728473e-25 - fConst34)) - 2.74055975769674e-24)) - 3.78141066792101e-21)));
	fConst70 = (2.13208229658786e-19 + (fConst0 * ((fConst0 * (7.2517402922623e-21 + (fConst0 * (fConst38 - 4.35717847353048e-23)))) - 3.2657449261887e-19)));
	fConst71 = (1.01125550937485e-33 + (fConst0 * (2.34447194587753e-19 + (fConst0 * ((fConst0 * (5.74453140263249e-23 + (fConst0 * (fConst40 - 1.73769177200289e-25)))) - 6.45410868622137e-21)))));
	fConst72 = (4.26416459317574e-19 + (fConst0 * ((fConst0 * (1.24168320637625e-20 + (fConst0 * ((fConst0 * (1.73769177200289e-25 - fConst40)) - 8.79647617632315e-23)))) - 5.2738887295382e-19)));
	fConst73 = ((fConst0 * ((fConst0 * (6.6938264041103e-22 + (fConst0 * (fConst44 - 7.01275323109138e-24)))) - 8.97810027051546e-21)) - 4.26416459317575e-19);
	fConst74 = ((fConst0 * (7.98442414323855e-17 + (fConst0 * ((fConst0 * (4.83270952225433e-22 - fConst46)) - 4.80207616341231e-19)))) - 3.68004528661724e-15);
	fConst75 = (1.01125550937485e-29 + (fConst0 * (2.15340311955366e-17 + (fConst0 * ((fConst0 * (3.53221173327878e-19 + (fConst0 * ((fConst0 * (2.52344661631536e-24 - fConst48)) - 2.18295349844616e-21)))) - 1.60655994099041e-17)))));
	fConst76 = (fConst0 * (2.32272470645234e-15 + (fConst0 * ((fConst0 * ((fConst0 * (2.18476286885277e-21 + (fConst0 * (fConst48 - 2.52344661631536e-24)))) - 8.46626752991924e-20)) - 3.4560962962513e-17))));
	fConst77 = (1.15181794887675e-27 * fConst0);
	fConst78 = ((fConst4 * ((fConst0 * (7.42323694913893e-25 - fConst77)) - 5.92825333627416e-23)) - 1.11238106031233e-34);
	fConst79 = (4.68894389175506e-19 + (fConst4 * (5.48111951539348e-24 + (fConst0 * (fConst77 - 7.42323694913893e-25)))));
	fConst80 = (1.535757265169e-25 * fConst0);
	fConst81 = (8.52832918635145e-19 + (fConst0 * ((fConst4 * (8.71435694706097e-23 - fConst80)) - 6.5314898523774e-19)));
	fConst82 = (5.2678616316051e-28 * fConst0);
	fConst83 = (4.0450220374994e-33 + (fConst0 * (4.68894389175505e-19 + (fConst4 * ((fConst0 * (6.95076708801156e-25 - fConst82)) - 1.1489062805265e-22)))));
	fConst84 = (1.70566583727029e-18 + (fConst0 * ((fConst4 * (1.75929523526463e-22 + (fConst0 * (fConst82 - 6.95076708801156e-25)))) - 1.05477774590764e-18)));
	fConst85 = (7.0238155088068e-26 * fConst0);
	fConst86 = ((fConst0 * ((fConst4 * (1.40255064621828e-23 - fConst85)) - 1.79562005410309e-20)) - 1.7056658372703e-18);
	fConst87 = (2.90298398976339e-25 * fConst0);
	fConst88 = ((fConst0 * (1.59688482864771e-16 + (fConst4 * (fConst87 - 9.66541904450867e-22)))) - 1.4720181146469e-14);
	fConst89 = (2.17723799232254e-27 * fConst0);
	fConst90 = (6.06753305624909e-29 + (fConst0 * (8.61361247821464e-17 + (fConst0 * ((fConst4 * (4.36590699689231e-21 + (fConst0 * (fConst89 - 1.00937864652614e-23)))) - 3.21311988198083e-17)))));
	fConst91 = (fConst0 * (9.29089882580934e-15 + (fConst0 * ((fConst4 * ((fConst0 * (1.00937864652614e-23 - fConst89)) - 4.36952573770555e-21)) - 6.91219259250261e-17))));
	fConst92 = (2.87954487219187e-27 * fConst0);
	fConst93 = (5.56190530156167e-35 + (fConst0 * (3.85251088052888e-21 + (fConst0 * ((fConst0 * (fConst92 - 9.27904618642366e-25)) - 2.96412666813708e-23)))));
	fConst94 = ((fConst0 * (1.1344232003763e-20 + (fConst0 * (2.74055975769674e-24 + (fConst0 * (9.27904618642366e-25 - fConst92)))))) - 2.34447194587753e-19);
	fConst95 = (1.91969658146125e-25 * fConst0);
	fConst96 = (1.06604114829393e-18 + (fConst0 * (3.2657449261887e-19 + (fConst0 * ((fConst0 * (4.35717847353048e-23 + fConst95)) - 2.17552208767869e-20)))));
	fConst97 = (1.31696540790127e-27 * fConst0);
	fConst98 = (5.05627754687424e-33 + (fConst0 * ((fConst0 * (1.93623260586641e-20 + (fConst0 * ((fConst0 * (fConst97 - 8.68845886001445e-25)) - 5.74453140263249e-23)))) - 2.34447194587753e-19)));
	fConst99 = (2.13208229658787e-18 + (fConst0 * (5.2738887295382e-19 + (fConst0 * ((fConst0 * (8.79647617632315e-23 + (fConst0 * (8.68845886001445e-25 - fConst97)))) - 3.72504961912875e-20)))));
	fConst100 = (8.7797693860085e-26 * fConst0);
	fConst101 = ((fConst0 * (8.97810027051546e-21 + (fConst0 * ((fConst0 * (7.01275323109138e-24 + fConst100)) - 2.00814792123309e-21)))) - 2.13208229658787e-18);
	fConst102 = (3.62872998720424e-25 * fConst0);
	fConst103 = ((fConst0 * ((fConst0 * (1.44062284902369e-18 + (fConst0 * (0 - (4.83270952225433e-22 + fConst102))))) - 7.98442414323855e-17)) - 1.84002264330862e-14);
	fConst104 = (5.44309498080636e-27 * fConst0);
	fConst105 = (1.51688326406227e-28 + (fConst0 * (1.07670155977683e-16 + (fConst0 * (1.60655994099041e-17 + (fConst0 * ((fConst0 * (2.18295349844616e-21 + (fConst0 * (1.26172330815768e-23 - fConst104)))) - 1.05966351998363e-18)))))));
	fConst106 = (fConst0 * (1.16136235322617e-14 + (fConst0 * (3.4560962962513e-17 + (fConst0 * (2.53988025897577e-19 + (fConst0 * ((fConst0 * (fConst104 - 1.26172330815768e-23)) - 2.18476286885277e-21))))))));
	fConst107 = (3.8393931629225e-27 * fConst4);
	fConst108 = (2.22476212062467e-34 + (fConst4 * (1.18565066725483e-22 - fConst107)));
	fConst109 = ((fConst4 * (fConst107 - 1.0962239030787e-23)) - 9.37788778351013e-19);
	fConst110 = (1.30629797047548e-18 - (1.74287138941219e-22 * fConst4));
	fConst111 = (1.7559538772017e-27 * fConst4);
	fConst112 = ((fConst4 * (2.297812561053e-22 - fConst111)) - 9.37788778351011e-19);
	fConst113 = (2.10955549181528e-18 + (fConst4 * (fConst111 - 3.51859047052926e-22)));
	fConst114 = (3.59124010820619e-20 - (2.80510129243655e-23 * fConst4));
	fConst115 = ((1.93308380890173e-21 * fConst4) - 3.19376965729542e-16);
	fConst116 = (7.25745997440848e-27 * fConst4);
	fConst117 = (2.0225110187497e-28 + (fConst4 * (6.42623976396166e-17 + (fConst4 * (fConst116 - 8.73181399378463e-21)))));
	fConst118 = (fConst4 * (1.38243851850052e-16 + (fConst4 * (8.73905147541109e-21 - fConst116))));
	fConst119 = (9.27904618642366e-25 + fConst92);
	fConst120 = (5.56190530156167e-35 + (fConst0 * ((fConst0 * ((fConst0 * fConst119) - 2.96412666813708e-23)) - 3.85251088052888e-21)));
	fConst121 = ((fConst0 * ((fConst0 * (2.74055975769674e-24 + (fConst0 * (0 - fConst119)))) - 1.1344232003763e-20)) - 2.34447194587753e-19);
	fConst122 = ((fConst0 * (3.2657449261887e-19 + (fConst0 * (2.17552208767869e-20 + (fConst0 * (4.35717847353048e-23 - fConst95)))))) - 1.06604114829393e-18);
	fConst123 = (8.68845886001445e-25 + fConst97);
	fConst124 = ((fConst0 * ((fConst0 * ((fConst0 * ((fConst0 * fConst123) - 5.74453140263249e-23)) - 1.93623260586641e-20)) - 2.34447194587753e-19)) - 5.05627754687424e-33);
	fConst125 = ((fConst0 * (5.2738887295382e-19 + (fConst0 * (3.72504961912875e-20 + (fConst0 * (8.79647617632315e-23 + (fConst0 * (0 - fConst123)))))))) - 2.13208229658787e-18);
	fConst126 = (2.13208229658787e-18 + (fConst0 * (8.97810027051546e-21 + (fConst0 * (2.00814792123309e-21 + (fConst0 * (7.01275323109138e-24 - fConst100)))))));
	fConst127 = (1.84002264330862e-14 + (fConst0 * ((fConst0 * ((fConst0 * (fConst102 - 4.83270952225433e-22)) - 1.44062284902369e-18)) - 7.98442414323855e-17)));
	fConst128 = (1.26172330815768e-23 + fConst104);
	fConst129 = (1.51688326406227e-28 + (fConst0 * ((fConst0 * (1.60655994099041e-17 + (fConst0 * (1.05966351998363e-18 + (fConst0 * (2.18295349844616e-21 + (fConst0 * (0 - fConst128)))))))) - 1.07670155977683e-16)));
	fConst130 = (fConst0 * ((fConst0 * (3.4560962962513e-17 + (fConst0 * ((fConst0 * ((fConst0 * fConst128) - 2.18476286885277e-21)) - 2.53988025897577e-19)))) - 1.16136235322617e-14));
	fConst131 = (7.42323694913893e-25 + fConst77);
	fConst132 = ((fConst4 * ((fConst0 * (0 - fConst131)) - 5.92825333627416e-23)) - 1.11238106031233e-34);
	fConst133 = (4.68894389175506e-19 + (fConst4 * (5.48111951539348e-24 + (fConst0 * fConst131))));
	fConst134 = ((fConst0 * ((fConst4 * (8.71435694706097e-23 + fConst80)) - 6.5314898523774e-19)) - 8.52832918635145e-19);
	fConst135 = (6.95076708801156e-25 + fConst82);
	fConst136 = ((fConst0 * (4.68894389175505e-19 + (fConst4 * ((fConst0 * (0 - fConst135)) - 1.1489062805265e-22)))) - 4.0450220374994e-33);
	fConst137 = ((fConst0 * ((fConst4 * (1.75929523526463e-22 + (fConst0 * fConst135))) - 1.05477774590764e-18)) - 1.70566583727029e-18);
	fConst138 = (1.7056658372703e-18 + (fConst0 * ((fConst4 * (1.40255064621828e-23 + fConst85)) - 1.79562005410309e-20)));
	fConst139 = (1.4720181146469e-14 + (fConst0 * (1.59688482864771e-16 + (fConst4 * (0 - (9.66541904450867e-22 + fConst87))))));
	fConst140 = (1.00937864652614e-23 + fConst89);
	fConst141 = (6.06753305624909e-29 + (fConst0 * ((fConst0 * ((fConst4 * (4.36590699689231e-21 + (fConst0 * fConst140))) - 3.21311988198083e-17)) - 8.61361247821464e-17)));
	fConst142 = (fConst0 * ((fConst0 * ((fConst4 * ((fConst0 * (0 - fConst140)) - 4.36952573770555e-21)) - 6.91219259250261e-17)) - 9.29089882580934e-15));
	fConst143 = (6.60055889302811e-27 * fConst0);
	fConst144 = (4.53515944167461e-24 - fConst143);
	fConst145 = (fConst143 - 4.53515944167461e-24);
	fConst146 = (8.80074519070414e-25 * fConst0);
	fConst147 = (8.59358765001811e-23 - fConst146);
	fConst148 = (2.08148895037469e-26 * fConst0);
	fConst149 = (4.5558751957432e-22 + (fConst0 * (fConst148 - 1.49225548879691e-23)));
	fConst150 = ((fConst0 * (1.49225548879691e-23 - fConst148)) - 9.17395143164286e-22);
	fConst151 = (2.77531860049959e-24 * fConst0);
	fConst152 = (fConst151 - 7.9172000495e-22);
	fConst153 = (4.83924092417224e-26 * fConst0);
	fConst154 = (0 - (4.32656348364945e-21 + fConst153));
	fConst155 = (3.62943069312918e-28 * fConst0);
	fConst156 = (4.32474721327688e-23 + fConst155);
	fConst157 = ((fConst4 * (2.23134556801112e-20 + (fConst0 * (0 - fConst156)))) - 1.96511367935993e-32);
	fConst158 = (1.96511367935993e-32 + (fConst4 * ((fConst0 * fConst156) - 2.23103456281034e-20)));
	fConst159 = (1.65013972325703e-26 * fConst0);
	fConst160 = (fConst159 - 5.66894930209326e-24);
	fConst161 = (5.66894930209326e-24 - fConst159);
	fConst162 = (1.10009314883802e-24 * fConst0);
	fConst163 = (4.29679382500905e-23 + fConst162);
	fConst164 = (5.20372237593672e-26 * fConst0);
	fConst165 = (2.2779375978716e-22 + (fConst0 * (1.86531936099614e-23 - fConst164)));
	fConst166 = ((fConst0 * (fConst164 - 1.86531936099614e-23)) - 4.58697571582143e-22);
	fConst167 = (3.46914825062448e-24 * fConst0);
	fConst168 = ((fConst0 * (0 - (3.95860002475e-22 + fConst167))) - 1.24294524411622e-21);
	fConst169 = (6.0490511552153e-26 * fConst0);
	fConst170 = (1.20962211270821e-18 + (fConst0 * (fConst169 - 2.16328174182473e-21)));
	fConst171 = (9.07357673282294e-28 * fConst0);
	fConst172 = (5.4059340165961e-23 + fConst171);
	fConst173 = (9.82556839679967e-33 + (fConst0 * (6.27687348278688e-20 + (fConst0 * (1.11567278400556e-20 + (fConst0 * fConst172))))));
	fConst174 = ((fConst0 * (6.77042258616489e-18 + (fConst0 * ((fConst0 * (0 - fConst172)) - 1.11551728140517e-20)))) - 9.82556839679967e-33);
	fConst175 = (6.93829650124896e-26 * fConst4);
	fConst176 = (fConst175 - 9.1117503914864e-22);
	fConst177 = (1.83479028632857e-21 - fConst175);
	fConst178 = (1.20981023104306e-27 * fConst4);
	fConst179 = (3.93022735871987e-32 + (fConst4 * (0 - (4.46269113602224e-20 + fConst178))));
	fConst180 = ((fConst4 * (4.46206912562068e-20 + fConst178)) - 3.93022735871987e-32);
	fConst181 = (5.66894930209326e-24 + fConst159);
	fConst182 = (0 - fConst181);
	fConst183 = (4.29679382500905e-23 - fConst162);
	fConst184 = (1.86531936099614e-23 + fConst164);
	fConst185 = (2.2779375978716e-22 + (fConst0 * (0 - fConst184)));
	fConst186 = ((fConst0 * fConst184) - 4.58697571582143e-22);
	fConst187 = (1.24294524411622e-21 + (fConst0 * (fConst167 - 3.95860002475e-22)));
	fConst188 = ((fConst0 * (0 - (2.16328174182473e-21 + fConst169))) - 1.20962211270821e-18);
	fConst189 = (9.82556839679967e-33 + (fConst0 * ((fConst0 * (1.11567278400556e-20 + (fConst0 * (fConst171 - 5.4059340165961e-23)))) - 6.27687348278688e-20)));
	fConst190 = ((fConst0 * ((fConst0 * ((fConst0 * (5.4059340165961e-23 - fConst171)) - 1.11551728140517e-20)) - 6.77042258616489e-18)) - 9.82556839679967e-33);
	fConst191 = (7.9172000495e-22 + fConst151);
	fConst192 = (4.53515944167461e-24 + fConst143);
	fConst193 = (0 - fConst192);
	fConst194 = (8.59358765001811e-23 + fConst146);
	fConst195 = (1.49225548879691e-23 + fConst148);
	fConst196 = (4.5558751957432e-22 + (fConst0 * fConst195));
	fConst197 = ((fConst0 * (0 - fConst195)) - 9.17395143164286e-22);
	fConst198 = (fConst153 - 4.32656348364945e-21);
	fConst199 = ((fConst4 * (2.23134556801112e-20 + (fConst0 * (4.32474721327688e-23 - fConst155)))) - 1.96511367935993e-32);
	fConst200 = (1.96511367935993e-32 + (fConst4 * ((fConst0 * (fConst155 - 4.32474721327688e-23)) - 2.23103456281034e-20)));
	fConst201 = (1.13378986041865e-24 + fConst52);
	fConst202 = (0 - fConst201);
	fConst203 = (0 - (4.29679382500905e-23 + fConst55));
	fConst204 = (3.73063872199228e-24 + fConst57);
	fConst205 = ((fConst0 * (0 - fConst204)) - 2.2779375978716e-22);
	fConst206 = (4.58697571582143e-22 + (fConst0 * fConst204));
	fConst207 = ((fConst0 * (3.95860002475e-22 + fConst60)) - 4.14315081372073e-22);
	fConst208 = (4.03207370902736e-19 + (fConst0 * (2.16328174182473e-21 - fConst62)));
	fConst209 = ((fConst0 * (2.09229116092896e-20 + (fConst0 * ((fConst0 * (fConst64 - 1.08118680331922e-23)) - 1.11567278400556e-20)))) - 9.82556839679967e-33);
	fConst210 = (9.82556839679967e-33 + (fConst0 * (2.25680752872163e-18 + (fConst0 * (1.11551728140517e-20 + (fConst0 * (1.08118680331922e-23 - fConst64)))))));
	fConst211 = (2.2147737670537e-26 * fConst0);
	fConst212 = (2.21955383001772e-15 + (fConst0 * ((fConst0 * (2.76366301878405e-15 + (fConst0 * ((fConst0 * (8.20289496101997e-19 - fConst211)) - 1.07989398172656e-16)))) - 1.68022586665737e-16)));
	fConst213 = (1.10738688352685e-25 * fConst0);
	fConst214 = (1.10977691500886e-14 + (fConst0 * ((fConst0 * (2.76366301878405e-15 + (fConst0 * (1.07989398172656e-16 + (fConst0 * (fConst213 - 2.46086848830599e-18)))))) - 5.04067759997212e-16)));
	fConst215 = (2.2147737670537e-25 * fConst0);
	fConst216 = (2.21955383001772e-14 + (fConst0 * ((fConst0 * ((fConst0 * (2.15978796345312e-16 + (fConst0 * (1.64057899220399e-18 - fConst215)))) - 5.5273260375681e-15)) - 3.36045173331475e-16)));
	fConst217 = (2.21955383001772e-14 + (fConst0 * (3.36045173331475e-16 + (fConst0 * ((fConst0 * ((fConst0 * (1.64057899220399e-18 + fConst215)) - 2.15978796345312e-16)) - 5.5273260375681e-15)))));
	fConst218 = (1.10977691500886e-14 + (fConst0 * (5.04067759997212e-16 + (fConst0 * (2.76366301878405e-15 + (fConst0 * ((fConst0 * (0 - (2.46086848830599e-18 + fConst213))) - 1.07989398172656e-16)))))));
	fConst219 = (2.21955383001772e-15 + (fConst0 * (1.68022586665737e-16 + (fConst0 * (2.76366301878405e-15 + (fConst0 * (1.07989398172656e-16 + (fConst0 * (8.20289496101997e-19 + fConst211)))))))));
	fConst220 = (3.22912277501057e-21 * fConst0);
	fConst221 = (2.78116542918484e-14 + (fConst0 * (fConst220 - 6.38442519444497e-17)));
	fConst222 = (1.27688503888899e-16 * fConst0);
	fConst223 = (1.11246617167394e-13 - fConst222);
	fConst224 = (1.29164911000423e-20 * fConst0);
	fConst225 = (1.11246617167394e-13 + (fConst0 * (1.27688503888899e-16 - fConst224)));
	fConst226 = (3.83065511666698e-16 * fConst0);
	fConst227 = (fConst226 - 1.11246617167394e-13);
	fConst228 = ((1.93747366500634e-20 * fConst4) - 2.78116542918484e-13);
	fConst229 = (0 - (1.11246617167394e-13 + fConst226));
	fConst230 = (1.11246617167394e-13 + (fConst0 * (0 - (1.27688503888899e-16 + fConst224))));
	fConst231 = (1.11246617167394e-13 + fConst222);
	fConst232 = (2.78116542918484e-14 + (fConst0 * (6.38442519444497e-17 + fConst220)));
	fConst233 = (fConst4 / fConst14);
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
#define fslider3 (*fslider3_)
	double 	fSlow0 = (0.007000000000000006 * double(fslider0));
	double 	fSlow1 = (0.007000000000000006 * double(fslider1));
	double 	fSlow2 = (0.007000000000000006 * double(fslider2));
	double 	fSlow3 = (0.0010956234992476606 * (exp((2 * double(fslider3))) - 1));
	for (int i=0; i<count; i++) {
		fRec1[0] = (fSlow0 + (0.993 * fRec1[1]));
		double fTemp0 = (fConst21 + (fRec1[0] * (fConst19 + (fConst17 * fRec1[0]))));
		fRec4[0] = (fSlow1 + (0.993 * fRec4[1]));
		fRec5[0] = (fSlow2 + (0.993 * fRec5[1]));
		double fTemp1 = (5.11699751181088e-15 + ((fRec4[0] * (fConst51 + (fConst50 * fRec4[0]))) + (fConst0 * (fConst47 + (fRec5[0] * (fConst45 + ((fRec4[0] * (fConst43 + (fConst42 * fRec4[0]))) + (fRec5[0] * (fConst39 + (fRec4[0] * ((fConst0 * (fConst37 + (fConst36 * fRec4[0]))) - 1.01125550937485e-33)))))))))));
		fRec7[0] = (fSlow3 + (0.993 * fRec7[1]));
		double fTemp2 = (4.78532903360752e-05 * fRec7[0]);
		double fTemp3 = (0.00103650226867939 + (fConst0 * (7.81957120982477e-06 + (fRec7[0] * (4.99109818205264e-05 - fTemp2)))));
		double fTemp4 = (1.82229840632861e-06 + (9.11149203164306e-05 * fRec7[0]));
		fRec8[0] = ((double)input0[i] - ((fRec8[1] * (0.00103650226867939 + (fConst0 * ((fRec7[0] * (fTemp2 - 4.99109818205264e-05)) - 7.81957120982477e-06)))) / fTemp3));
		fRec6[0] = ((fConst0 * (((fRec8[1] * fTemp4) + (fRec8[0] * (0 - fTemp4))) / fTemp3)) - (((((((fRec6[1] * (3.07019850708653e-14 + ((fRec4[0] * (fConst142 + (fConst141 * fRec4[0]))) + (fConst0 * (fConst139 + (fRec5[0] * (fConst138 + ((fRec4[0] * (fConst137 + (fConst136 * fRec4[0]))) + (fRec5[0] * (fConst134 + (fRec4[0] * ((fConst0 * (fConst133 + (fConst132 * fRec4[0]))) - 4.0450220374994e-33)))))))))))) + (fRec6[2] * (7.67549626771633e-14 + ((fRec4[0] * (fConst130 + (fConst129 * fRec4[0]))) + (fConst0 * (fConst127 + (fRec5[0] * (fConst126 + ((fRec4[0] * (fConst125 + (fConst124 * fRec4[0]))) + (fRec5[0] * (fConst122 + (fRec4[0] * ((fConst0 * (fConst121 + (fConst120 * fRec4[0]))) - 5.05627754687424e-33))))))))))))) + (fRec6[3] * (1.02339950236218e-13 + ((fRec4[0] * (fConst118 + (fConst117 * fRec4[0]))) + (fConst4 * (fConst115 + (fRec5[0] * (fConst114 + ((fRec4[0] * (fConst113 + (fConst112 * fRec4[0]))) + (fRec5[0] * (fConst110 + (fRec4[0] * (fConst109 + (fConst108 * fRec4[0])))))))))))))) + (fRec6[4] * (7.67549626771633e-14 + ((fRec4[0] * (fConst106 + (fConst105 * fRec4[0]))) + (fConst0 * (fConst103 + (fRec5[0] * (fConst101 + ((fRec4[0] * (fConst99 + (fConst98 * fRec4[0]))) + (fRec5[0] * (fConst96 + (fRec4[0] * (5.05627754687424e-33 + (fConst0 * (fConst94 + (fConst93 * fRec4[0])))))))))))))))) + (fRec6[5] * (3.07019850708653e-14 + ((fRec4[0] * (fConst91 + (fConst90 * fRec4[0]))) + (fConst0 * (fConst88 + (fRec5[0] * (fConst86 + ((fRec4[0] * (fConst84 + (fConst83 * fRec4[0]))) + (fRec5[0] * (fConst81 + (fRec4[0] * (4.0450220374994e-33 + (fConst0 * (fConst79 + (fConst78 * fRec4[0])))))))))))))))) + (fRec6[6] * (5.11699751181088e-15 + ((fRec4[0] * (fConst76 + (fConst75 * fRec4[0]))) + (fConst0 * (fConst74 + (fRec5[0] * (fConst73 + ((fRec4[0] * (fConst72 + (fConst71 * fRec4[0]))) + (fRec5[0] * (fConst70 + (fRec4[0] * (1.01125550937485e-33 + (fConst0 * (fConst69 + (fConst68 * fRec4[0])))))))))))))))) / fTemp1));
		fRec3[0] = ((fConst4 * ((((((((fRec6[0] * (((fRec4[0] * (fConst210 + (fConst209 * fRec4[0]))) + (fConst0 * (fConst208 + (fRec5[0] * (fConst207 + ((fRec4[0] * (4.14315081372074e-22 + (fConst0 * (fConst206 + (fConst205 * fRec4[0]))))) + (fRec5[0] * (2.07157540686037e-22 + (fConst0 * (fConst203 + (fRec4[0] * ((fConst0 * (fConst202 + (fConst201 * fRec4[0]))) - 2.27793759787161e-22)))))))))))) - 4.97178097646487e-18)) + (fRec6[1] * (((fRec4[0] * (fConst200 + (fConst199 * fRec4[0]))) + (fConst4 * (fConst198 + (fRec5[0] * (((fRec4[0] * (fConst197 + (fConst196 * fRec4[0]))) + (fRec5[0] * (fConst194 + (fRec4[0] * (4.55587519574321e-22 + (fConst0 * (fConst192 + (fConst193 * fRec4[0])))))))) - fConst191))))) - 9.94356195292975e-18))) + (fRec6[2] * (4.97178097646487e-18 + ((fRec4[0] * (fConst190 + (fConst189 * fRec4[0]))) + (fConst0 * (fConst188 + (fRec5[0] * (fConst187 + ((fRec4[0] * ((fConst0 * (fConst186 + (fConst185 * fRec4[0]))) - 1.24294524411622e-21)) + (fRec5[0] * ((fConst0 * (fConst183 + (fRec4[0] * (2.27793759787161e-22 + (fConst0 * (fConst182 + (fConst181 * fRec4[0]))))))) - 6.21472622058109e-22))))))))))) + (fRec6[3] * (1.98871239058595e-17 + ((fRec4[0] * (fConst180 + (fConst179 * fRec4[0]))) + (fConst4 * (8.6531269672989e-21 + (fRec5[0] * (1.5834400099e-21 + ((fRec4[0] * (fConst177 + (fConst176 * fRec4[0]))) + (fRec5[0] * ((fRec4[0] * ((fConst4 * (2.20018629767604e-26 + (0 - (2.20018629767604e-26 * fRec4[0])))) - 9.11175039148642e-22)) - 1.71871753000362e-22))))))))))) + (fRec6[4] * (4.97178097646487e-18 + ((fRec4[0] * (fConst174 + (fConst173 * fRec4[0]))) + (fConst0 * (fConst170 + (fRec5[0] * (fConst168 + ((fRec4[0] * (1.24294524411622e-21 + (fConst0 * (fConst166 + (fConst165 * fRec4[0]))))) + (fRec5[0] * (6.21472622058109e-22 + (fConst0 * (fConst163 + (fRec4[0] * (2.27793759787161e-22 + (fConst0 * (fConst161 + (fConst160 * fRec4[0])))))))))))))))))) + (fRec6[5] * (((fRec4[0] * (fConst158 + (fConst157 * fRec4[0]))) + (fConst4 * (fConst154 + (fRec5[0] * (fConst152 + ((fRec4[0] * (fConst150 + (fConst149 * fRec4[0]))) + (fRec5[0] * (fConst147 + (fRec4[0] * (4.55587519574321e-22 + (fConst0 * (fConst145 + (fConst144 * fRec4[0]))))))))))))) - 9.94356195292975e-18))) + (fRec6[6] * (((fRec4[0] * (fConst67 + (fConst66 * fRec4[0]))) + (fConst0 * (fConst63 + (fRec5[0] * (fConst61 + ((fRec4[0] * ((fConst0 * (fConst59 + (fConst58 * fRec4[0]))) - 4.14315081372074e-22)) + (fRec5[0] * ((fConst0 * (fConst56 + (fRec4[0] * ((fConst0 * (fConst54 + (fConst53 * fRec4[0]))) - 2.27793759787161e-22)))) - 2.07157540686037e-22)))))))) - 4.97178097646487e-18))) / fTemp1)) - (fConst33 * (((((fConst32 * fRec3[1]) + (fConst31 * fRec3[2])) + (fConst30 * fRec3[3])) + (fConst28 * fRec3[4])) + (fConst26 * fRec3[5]))));
		fRec2[0] = (supersonicclip((fConst33 * ((((((fConst219 * fRec3[0]) + (fConst218 * fRec3[1])) + (fConst217 * fRec3[2])) + (fConst216 * fRec3[3])) + (fConst214 * fRec3[4])) + (fConst212 * fRec3[5])))) - ((fRec2[1] * (fConst24 + (fRec1[0] * ((fConst23 * fRec1[0]) - fConst22)))) / fTemp0));
		fRec0[0] = (((((fRec1[0] * ((0.488938774271564 * fRec1[0]) - 1.61349795509616)) - 0.166239183252332) * (fRec2[1] + fRec2[0])) / fTemp0) - (fConst15 * ((((((((fConst13 * fRec0[1]) + (fConst12 * fRec0[2])) + (fConst11 * fRec0[3])) + (fConst10 * fRec0[4])) + (fConst9 * fRec0[5])) + (fConst7 * fRec0[6])) + (fConst5 * fRec0[7])) + (fConst2 * fRec0[8]))));
		output0[i] = (FAUSTFLOAT)(fConst233 * (((((((((fConst232 * fRec0[0]) + (fConst231 * fRec0[1])) + (fConst230 * fRec0[2])) + (fConst229 * fRec0[3])) + (fConst228 * fRec0[4])) + (fConst227 * fRec0[5])) + (fConst225 * fRec0[6])) + (fConst223 * fRec0[7])) + (fConst221 * fRec0[8])));
		// post processing
		for (int i=8; i>0; i--) fRec0[i] = fRec0[i-1];
		fRec2[1] = fRec2[0];
		for (int i=5; i>0; i--) fRec3[i] = fRec3[i-1];
		for (int i=6; i>0; i--) fRec6[i] = fRec6[i-1];
		fRec8[1] = fRec8[0];
		fRec7[1] = fRec7[0];
		fRec5[1] = fRec5[0];
		fRec4[1] = fRec4[0];
		fRec1[1] = fRec1[0];
	}
#undef fslider0
#undef fslider1
#undef fslider2
#undef fslider3
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
		fslider1_ = (float*)data; // , 0.5, 0.0, 1.0, 0.01 
		break;
	case GAIN: 
		fslider3_ = (float*)data; // , 0.5, 0.0, 1.0, 0.01 
		break;
	case TREBLE: 
		fslider2_ = (float*)data; // , 0.5, 0.0, 1.0, 0.01 
		break;
	case VOLUME: 
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
   BASS, 
   GAIN, 
   TREBLE, 
   VOLUME, 
} PortIndex;
*/

} // end namespace supersonic
