// generated from file './/mbr1on.dsp' by dsp2cc:
// Code generated with Faust 0.9.73 (http://faust.grame.fr)


namespace mbr1on {

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
	FAUSTFLOAT 	fslider0;
	FAUSTFLOAT	*fslider0_;
	double 	fRec0[2];
	double 	fConst7;
	double 	fConst8;
	double 	fConst9;
	double 	fConst10;
	FAUSTFLOAT 	fslider1;
	FAUSTFLOAT	*fslider1_;
	double 	fRec1[2];
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
	double 	fRec2[6];
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
	FAUSTFLOAT 	fslider2;
	FAUSTFLOAT	*fslider2_;
	double 	fRec3[2];
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
	name = N_("MBR1ON");
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
	for (int i=0; i<2; i++) fRec1[i] = 0;
	for (int i=0; i<6; i++) fRec2[i] = 0;
	for (int i=0; i<2; i++) fRec3[i] = 0;
}

void Dsp::clear_state_f_static(PluginLV2 *p)
{
	static_cast<Dsp*>(p)->clear_state_f();
}

inline void Dsp::init(uint32_t samplingFreq)
{
	fSamplingFreq = samplingFreq;
	fConst0 = double(min(192000, max(1, fSamplingFreq)));
	fConst1 = (1.18330530969519e-25 * fConst0);
	fConst2 = (5.94203392954467e-12 + (fConst0 * (9.92898924376863e-15 + (fConst0 * (2.17075680616335e-18 + (fConst0 * (9.73577852885708e-22 + fConst1)))))));
	fConst3 = (3.85860427074518e-27 * fConst0);
	fConst4 = (5.84149813210035e-14 + (fConst0 * (5.26699482956717e-16 + (fConst0 * (7.45139358061681e-19 + (fConst0 * (1.1380738929659e-22 + fConst3)))))));
	fConst5 = (4.28733807860576e-27 * fConst0);
	fConst6 = ((fConst0 * ((fConst0 * ((fConst0 * (0 - (1.28834509262103e-22 + fConst5))) - 7.80295530306248e-19)) - 1.5648783986911e-16)) - 5.3591725982572e-15);
	fConst7 = (4.28733807860576e-25 * fConst0);
	fConst8 = (fConst0 * (1.17901797161658e-14 + (fConst0 * (7.76008192227642e-17 + (fConst0 * (1.29048876166033e-20 + fConst7))))));
	fConst9 = (4.2444646978197e-25 * fConst0);
	fConst10 = ((fConst0 * ((fConst0 * ((fConst0 * (0 - (1.27977041646382e-20 + fConst9))) - 7.74721990804061e-17)) - 1.55416005349459e-14)) - 5.3591725982572e-13);
	fConst11 = (3.42987046288461e-25 * fConst0);
	fConst12 = ((fConst0 * ((fConst0 * ((fConst0 * (0 - (1.22574995667339e-20 + fConst11))) - 8.18452839205839e-17)) - 5.02690389716525e-14)) - 5.3591725982572e-12);
	fConst13 = (3.39128442017716e-25 * fConst0);
	fConst14 = (5.84149813210035e-12 + (fConst0 * (5.36453177085546e-14 + (fConst0 * (8.17295257924616e-17 + (fConst0 * (1.21610344599652e-20 + fConst13)))))));
	fConst15 = (1.28294304664199e-23 * fConst0);
	fConst16 = (6.32838466389946e-08 + (fConst0 * (6.04351613406486e-10 + (fConst0 * (1.06857112561395e-12 + (fConst0 * (2.3142517311553e-16 + (fConst0 * (1.04945005388316e-19 + fConst15)))))))));
	fConst17 = (1.29477609973894e-23 * fConst0);
	fConst18 = ((fConst0 * ((fConst0 * ((fConst0 * ((fConst0 * (0 - (1.05265278664784e-19 + fConst17))) - 2.28565746666998e-16)) - 1.06911160387173e-12)) - 5.60398416354354e-10)) - 5.70124744495447e-08);
	fConst19 = (1.07183451965144e-26 * fConst0);
	fConst20 = ((fConst0 * (5.96920607486733e-16 + (fConst0 * ((fConst0 * (1.0771936922497e-22 - fConst19)) - 2.75997388810246e-19)))) - 2.85062372247723e-12);
	fConst21 = (1.07183451965144e-23 * fConst0);
	fConst22 = ((fConst0 * (1.07183451965144e-17 + (fConst0 * (fConst21 - 5.46635605022234e-20)))) - 2.6795862991286e-14);
	fConst23 = (1.06111617445493e-23 * fConst0);
	fConst24 = (2.6795862991286e-14 + (fConst0 * ((fConst0 * (5.46635605022234e-20 - fConst23)) - 1.3397931495643e-17)));
	fConst25 = (1.07183451965144e-25 * fConst0);
	fConst26 = (2.6795862991286e-16 + (fConst0 * ((fConst0 * (5.41276432423977e-22 - fConst25)) - 8.0387588973858e-20)));
	fConst27 = (2.14366903930288e-24 * fConst0);
	fConst28 = (2.85062372247723e-10 + (fConst0 * ((fConst0 * (3.92701924008464e-17 + (fConst0 * (fConst27 - 1.61847012467367e-20)))) - 1.16704535198218e-13)));
	fConst29 = (2.13295069410637e-24 * fConst0);
	fConst30 = ((fConst0 * (1.16704535198218e-13 + (fConst0 * ((fConst0 * (1.61847012467367e-20 - fConst29)) - 3.95381510307592e-17)))) - 2.85062372247723e-10);
	fConst31 = ((fConst0 * (9.92898924376863e-15 + (fConst0 * ((fConst0 * (9.73577852885708e-22 - fConst1)) - 2.17075680616335e-18)))) - 5.94203392954467e-12);
	fConst32 = ((fConst0 * (5.26699482956717e-16 + (fConst0 * ((fConst0 * (1.1380738929659e-22 - fConst3)) - 7.45139358061681e-19)))) - 5.84149813210035e-14);
	fConst33 = (5.3591725982572e-15 + (fConst0 * ((fConst0 * (7.80295530306248e-19 + (fConst0 * (fConst5 - 1.28834509262103e-22)))) - 1.5648783986911e-16)));
	fConst34 = (fConst0 * (1.17901797161658e-14 + (fConst0 * ((fConst0 * (1.29048876166033e-20 - fConst7)) - 7.76008192227642e-17))));
	fConst35 = (5.3591725982572e-13 + (fConst0 * ((fConst0 * (7.74721990804061e-17 + (fConst0 * (fConst9 - 1.27977041646382e-20)))) - 1.55416005349459e-14)));
	fConst36 = (5.3591725982572e-12 + (fConst0 * ((fConst0 * (8.18452839205839e-17 + (fConst0 * (fConst11 - 1.22574995667339e-20)))) - 5.02690389716525e-14)));
	fConst37 = ((fConst0 * (5.36453177085546e-14 + (fConst0 * ((fConst0 * (1.21610344599652e-20 - fConst13)) - 8.17295257924616e-17)))) - 5.84149813210035e-12);
	fConst38 = (6.32838466389946e-08 + (fConst0 * ((fConst0 * (1.06857112561395e-12 + (fConst0 * ((fConst0 * (1.04945005388316e-19 - fConst15)) - 2.3142517311553e-16)))) - 6.04351613406486e-10)));
	fConst39 = ((fConst0 * (5.60398416354354e-10 + (fConst0 * ((fConst0 * (2.28565746666998e-16 + (fConst0 * (fConst17 - 1.05265278664784e-19)))) - 1.06911160387173e-12)))) - 5.70124744495447e-08);
	fConst40 = (5.91652654847595e-25 * fConst0);
	fConst41 = ((fConst0 * (9.92898924376863e-15 + (fConst0 * (2.17075680616335e-18 + (fConst0 * (fConst40 - 2.92073355865712e-21)))))) - 1.7826101788634e-11);
	fConst42 = (1.92930213537259e-26 * fConst0);
	fConst43 = ((fConst0 * (5.26699482956717e-16 + (fConst0 * (7.45139358061681e-19 + (fConst0 * (fConst42 - 3.4142216788977e-22)))))) - 1.7524494396301e-13);
	fConst44 = (2.14366903930288e-26 * fConst0);
	fConst45 = (1.60775177947716e-14 + (fConst0 * ((fConst0 * ((fConst0 * (3.86503527786309e-22 - fConst44)) - 7.80295530306248e-19)) - 1.5648783986911e-16)));
	fConst46 = (fConst0 * (1.17901797161658e-14 + (fConst0 * (7.76008192227642e-17 + (fConst0 * (fConst27 - 3.871466284981e-20))))));
	fConst47 = (2.12223234890985e-24 * fConst0);
	fConst48 = (1.60775177947716e-12 + (fConst0 * ((fConst0 * ((fConst0 * (3.83931124939146e-20 - fConst47)) - 7.74721990804061e-17)) - 1.55416005349459e-14)));
	fConst49 = (1.7149352314423e-24 * fConst0);
	fConst50 = (1.60775177947716e-11 + (fConst0 * ((fConst0 * ((fConst0 * (3.67724987002016e-20 - fConst49)) - 8.18452839205839e-17)) - 5.02690389716525e-14)));
	fConst51 = (1.69564221008858e-24 * fConst0);
	fConst52 = ((fConst0 * (5.36453177085546e-14 + (fConst0 * (8.17295257924616e-17 + (fConst0 * (fConst51 - 3.64831033798957e-20)))))) - 1.7524494396301e-11);
	fConst53 = (6.41471523320994e-23 * fConst0);
	fConst54 = (3.16419233194973e-07 + (fConst0 * ((fConst0 * (1.06857112561395e-12 + (fConst0 * (2.3142517311553e-16 + (fConst0 * (fConst53 - 3.14835016164948e-19)))))) - 1.81305484021946e-09)));
	fConst55 = (6.4738804986947e-23 * fConst0);
	fConst56 = ((fConst0 * (1.68119524906306e-09 + (fConst0 * ((fConst0 * ((fConst0 * (3.15795835994352e-19 - fConst55)) - 2.28565746666998e-16)) - 1.06911160387173e-12)))) - 2.85062372247723e-07);
	fConst57 = (1.18330530969519e-24 * fConst0);
	fConst58 = ((fConst0 * ((fConst0 * (4.34151361232669e-18 + (fConst0 * (1.94715570577142e-21 - fConst57)))) - 1.98579784875373e-14)) - 1.18840678590893e-11);
	fConst59 = (3.85860427074518e-26 * fConst0);
	fConst60 = ((fConst0 * ((fConst0 * (1.49027871612336e-18 + (fConst0 * (2.2761477859318e-22 - fConst59)))) - 1.05339896591343e-15)) - 1.16829962642007e-13);
	fConst61 = (4.28733807860576e-26 * fConst0);
	fConst62 = (1.07183451965144e-14 + (fConst0 * (3.1297567973822e-16 + (fConst0 * ((fConst0 * (fConst61 - 2.57669018524206e-22)) - 1.5605910606125e-18)))));
	fConst63 = (4.28733807860576e-24 * fConst0);
	fConst64 = (fConst0 * ((fConst0 * (1.55201638445528e-16 + (fConst0 * (2.58097752332067e-20 - fConst63)))) - 2.35803594323317e-14));
	fConst65 = (4.2444646978197e-24 * fConst0);
	fConst66 = (1.07183451965144e-12 + (fConst0 * (3.10832010698918e-14 + (fConst0 * ((fConst0 * (fConst65 - 2.55954083292764e-20)) - 1.54944398160812e-16)))));
	fConst67 = (3.42987046288461e-24 * fConst0);
	fConst68 = (1.07183451965144e-11 + (fConst0 * (1.00538077943305e-13 + (fConst0 * ((fConst0 * (fConst67 - 2.45149991334677e-20)) - 1.63690567841168e-16)))));
	fConst69 = (3.39128442017716e-24 * fConst0);
	fConst70 = ((fConst0 * ((fConst0 * (1.63459051584923e-16 + (fConst0 * (2.43220689199305e-20 - fConst69)))) - 1.07290635417109e-13)) - 1.16829962642007e-11);
	fConst71 = (1.28294304664199e-22 * fConst0);
	fConst72 = (6.32838466389946e-07 + (fConst0 * ((fConst0 * ((fConst0 * (4.62850346231061e-16 + (fConst0 * (2.09890010776632e-19 - fConst71)))) - 2.1371422512279e-12)) - 1.20870322681297e-09)));
	fConst73 = (1.29477609973894e-22 * fConst0);
	fConst74 = ((fConst0 * (1.12079683270871e-09 + (fConst0 * (2.13822320774346e-12 + (fConst0 * ((fConst0 * (fConst73 - 2.10530557329568e-19)) - 4.57131493333996e-16)))))) - 5.70124744495447e-07);
	fConst75 = (1.18840678590893e-11 + (fConst0 * ((fConst0 * ((fConst0 * (1.94715570577142e-21 + fConst57)) - 4.34151361232669e-18)) - 1.98579784875373e-14)));
	fConst76 = (1.16829962642007e-13 + (fConst0 * ((fConst0 * ((fConst0 * (2.2761477859318e-22 + fConst59)) - 1.49027871612336e-18)) - 1.05339896591343e-15)));
	fConst77 = ((fConst0 * (3.1297567973822e-16 + (fConst0 * (1.5605910606125e-18 + (fConst0 * (0 - (2.57669018524206e-22 + fConst61))))))) - 1.07183451965144e-14);
	fConst78 = (fConst0 * ((fConst0 * ((fConst0 * (2.58097752332067e-20 + fConst63)) - 1.55201638445528e-16)) - 2.35803594323317e-14));
	fConst79 = ((fConst0 * (3.10832010698918e-14 + (fConst0 * (1.54944398160812e-16 + (fConst0 * (0 - (2.55954083292764e-20 + fConst65))))))) - 1.07183451965144e-12);
	fConst80 = ((fConst0 * (1.00538077943305e-13 + (fConst0 * (1.63690567841168e-16 + (fConst0 * (0 - (2.45149991334677e-20 + fConst67))))))) - 1.07183451965144e-11);
	fConst81 = (1.16829962642007e-11 + (fConst0 * ((fConst0 * ((fConst0 * (2.43220689199305e-20 + fConst69)) - 1.63459051584923e-16)) - 1.07290635417109e-13)));
	fConst82 = (6.32838466389946e-07 + (fConst0 * (1.20870322681297e-09 + (fConst0 * ((fConst0 * ((fConst0 * (2.09890010776632e-19 + fConst71)) - 4.62850346231061e-16)) - 2.1371422512279e-12)))));
	fConst83 = ((fConst0 * ((fConst0 * (2.13822320774346e-12 + (fConst0 * (4.57131493333996e-16 + (fConst0 * (0 - (2.10530557329568e-19 + fConst73))))))) - 1.12079683270871e-09)) - 5.70124744495447e-07);
	fConst84 = (1.7826101788634e-11 + (fConst0 * (9.92898924376863e-15 + (fConst0 * ((fConst0 * (0 - (2.92073355865712e-21 + fConst40))) - 2.17075680616335e-18)))));
	fConst85 = (1.7524494396301e-13 + (fConst0 * (5.26699482956717e-16 + (fConst0 * ((fConst0 * (0 - (3.4142216788977e-22 + fConst42))) - 7.45139358061681e-19)))));
	fConst86 = ((fConst0 * ((fConst0 * (7.80295530306248e-19 + (fConst0 * (3.86503527786309e-22 + fConst44)))) - 1.5648783986911e-16)) - 1.60775177947716e-14);
	fConst87 = (fConst0 * (1.17901797161658e-14 + (fConst0 * ((fConst0 * (0 - (3.871466284981e-20 + fConst27))) - 7.76008192227642e-17))));
	fConst88 = ((fConst0 * ((fConst0 * (7.74721990804061e-17 + (fConst0 * (3.83931124939146e-20 + fConst47)))) - 1.55416005349459e-14)) - 1.60775177947716e-12);
	fConst89 = ((fConst0 * ((fConst0 * (8.18452839205839e-17 + (fConst0 * (3.67724987002016e-20 + fConst49)))) - 5.02690389716525e-14)) - 1.60775177947716e-11);
	fConst90 = (1.7524494396301e-11 + (fConst0 * (5.36453177085546e-14 + (fConst0 * ((fConst0 * (0 - (3.64831033798957e-20 + fConst51))) - 8.17295257924616e-17)))));
	fConst91 = (3.16419233194973e-07 + (fConst0 * (1.81305484021946e-09 + (fConst0 * (1.06857112561395e-12 + (fConst0 * ((fConst0 * (0 - (3.14835016164948e-19 + fConst53))) - 2.3142517311553e-16)))))));
	fConst92 = ((fConst0 * ((fConst0 * ((fConst0 * (2.28565746666998e-16 + (fConst0 * (3.15795835994352e-19 + fConst55)))) - 1.06911160387173e-12)) - 1.68119524906306e-09)) - 2.85062372247723e-07);
	fConst93 = (5.3591725982572e-26 * fConst0);
	fConst94 = ((fConst0 * (5.96920607486733e-16 + (fConst0 * (2.75997388810246e-19 + (fConst0 * (fConst93 - 3.23158107674909e-22)))))) - 8.5518711674317e-12);
	fConst95 = (5.3591725982572e-23 * fConst0);
	fConst96 = ((fConst0 * ((fConst0 * (1.6399068150667e-19 - fConst95)) - 1.07183451965144e-17)) - 2.6795862991286e-14);
	fConst97 = (5.30558087227463e-23 * fConst0);
	fConst98 = (2.6795862991286e-14 + (fConst0 * (1.3397931495643e-17 + (fConst0 * (fConst97 - 1.6399068150667e-19)))));
	fConst99 = (5.3591725982572e-25 * fConst0);
	fConst100 = (2.6795862991286e-16 + (fConst0 * (8.0387588973858e-20 + (fConst0 * (fConst99 - 1.62382929727193e-21)))));
	fConst101 = (8.5518711674317e-10 + (fConst0 * ((fConst0 * ((fConst0 * (4.85541037402102e-20 - fConst21)) - 3.92701924008464e-17)) - 1.16704535198218e-13)));
	fConst102 = (1.06647534705318e-23 * fConst0);
	fConst103 = ((fConst0 * (1.16704535198218e-13 + (fConst0 * (3.95381510307592e-17 + (fConst0 * (fConst102 - 4.85541037402102e-20)))))) - 8.5518711674317e-10);
	fConst104 = ((fConst0 * ((fConst0 * (5.51994777620491e-19 + (fConst0 * (2.15438738449939e-22 - fConst25)))) - 1.19384121497347e-15)) - 5.70124744495447e-12);
	fConst105 = (1.07183451965144e-22 * fConst0);
	fConst106 = (5.3591725982572e-14 + (fConst0 * ((fConst0 * (fConst105 - 1.09327121004447e-19)) - 2.14366903930288e-17)));
	fConst107 = (1.06111617445493e-22 * fConst0);
	fConst108 = ((fConst0 * (2.6795862991286e-17 + (fConst0 * (1.09327121004447e-19 - fConst107)))) - 5.3591725982572e-14);
	fConst109 = (1.07183451965144e-24 * fConst0);
	fConst110 = ((fConst0 * (1.60775177947716e-19 + (fConst0 * (1.08255286484795e-21 - fConst109)))) - 5.3591725982572e-16);
	fConst111 = (2.14366903930288e-23 * fConst0);
	fConst112 = (5.70124744495447e-10 + (fConst0 * (2.33409070396436e-13 + (fConst0 * ((fConst0 * (fConst111 - 3.23694024934735e-20)) - 7.85403848016927e-17)))));
	fConst113 = (2.13295069410637e-23 * fConst0);
	fConst114 = ((fConst0 * ((fConst0 * (7.90763020615185e-17 + (fConst0 * (3.23694024934735e-20 - fConst113)))) - 2.33409070396436e-13)) - 5.70124744495447e-10);
	fConst115 = (5.70124744495447e-12 + (fConst0 * ((fConst0 * ((fConst0 * (2.15438738449939e-22 + fConst25)) - 5.51994777620491e-19)) - 1.19384121497347e-15)));
	fConst116 = (5.3591725982572e-14 + (fConst0 * (2.14366903930288e-17 + (fConst0 * (0 - (1.09327121004447e-19 + fConst105))))));
	fConst117 = ((fConst0 * ((fConst0 * (1.09327121004447e-19 + fConst107)) - 2.6795862991286e-17)) - 5.3591725982572e-14);
	fConst118 = ((fConst0 * ((fConst0 * (1.08255286484795e-21 + fConst109)) - 1.60775177947716e-19)) - 5.3591725982572e-16);
	fConst119 = ((fConst0 * (2.33409070396436e-13 + (fConst0 * (7.85403848016927e-17 + (fConst0 * (0 - (3.23694024934735e-20 + fConst111))))))) - 5.70124744495447e-10);
	fConst120 = (5.70124744495447e-10 + (fConst0 * ((fConst0 * ((fConst0 * (3.23694024934735e-20 + fConst113)) - 7.90763020615185e-17)) - 2.33409070396436e-13)));
	fConst121 = (8.5518711674317e-12 + (fConst0 * (5.96920607486733e-16 + (fConst0 * ((fConst0 * (0 - (3.23158107674909e-22 + fConst93))) - 2.75997388810246e-19)))));
	fConst122 = ((fConst0 * (1.07183451965144e-17 + (fConst0 * (1.6399068150667e-19 + fConst95)))) - 2.6795862991286e-14);
	fConst123 = (2.6795862991286e-14 + (fConst0 * ((fConst0 * (0 - (1.6399068150667e-19 + fConst97))) - 1.3397931495643e-17)));
	fConst124 = (2.6795862991286e-16 + (fConst0 * ((fConst0 * (0 - (1.62382929727193e-21 + fConst99))) - 8.0387588973858e-20)));
	fConst125 = ((fConst0 * ((fConst0 * (3.92701924008464e-17 + (fConst0 * (4.85541037402102e-20 + fConst21)))) - 1.16704535198218e-13)) - 8.5518711674317e-10);
	fConst126 = (8.5518711674317e-10 + (fConst0 * (1.16704535198218e-13 + (fConst0 * ((fConst0 * (0 - (4.85541037402102e-20 + fConst102))) - 3.95381510307592e-17)))));
	fConst127 = (2.85062372247723e-12 + (fConst0 * (5.96920607486733e-16 + (fConst0 * (2.75997388810246e-19 + (fConst0 * (1.0771936922497e-22 + fConst19)))))));
	fConst128 = ((fConst0 * ((fConst0 * (0 - (5.46635605022234e-20 + fConst21))) - 1.07183451965144e-17)) - 2.6795862991286e-14);
	fConst129 = (2.6795862991286e-14 + (fConst0 * (1.3397931495643e-17 + (fConst0 * (5.46635605022234e-20 + fConst23)))));
	fConst130 = (2.6795862991286e-16 + (fConst0 * (8.0387588973858e-20 + (fConst0 * (5.41276432423977e-22 + fConst25)))));
	fConst131 = ((fConst0 * ((fConst0 * ((fConst0 * (0 - (1.61847012467367e-20 + fConst27))) - 3.92701924008464e-17)) - 1.16704535198218e-13)) - 2.85062372247723e-10);
	fConst132 = (2.85062372247723e-10 + (fConst0 * (1.16704535198218e-13 + (fConst0 * (3.95381510307592e-17 + (fConst0 * (1.61847012467367e-20 + fConst29)))))));
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
	double 	fSlow0 = (0.007000000000000006 * (1 - double(fslider0)));
	double 	fSlow1 = (0.007000000000000006 * double(fslider1));
	double 	fSlow2 = (4.748558434412966e-05 * (exp((5 * double(fslider2))) - 1));
	for (int i=0; i<count; i++) {
		fRec0[0] = ((0.993 * fRec0[1]) + fSlow0);
		fRec1[0] = ((0.993 * fRec1[1]) + fSlow1);
		double fTemp0 = (6.32838466389946e-10 + ((fRec0[0] * ((fConst18 * fRec0[0]) + fConst16)) + (fConst0 * ((fRec1[0] * (((fRec0[0] * (fConst14 + (fConst12 * fRec0[0]))) + (fRec1[0] * ((fRec0[0] * (fConst10 + (fConst8 * fRec0[0]))) + fConst6))) + fConst4)) + fConst2))));
		fRec2[0] = ((double)input0[i] - ((((((fRec2[1] * (3.16419233194973e-09 + ((fRec0[0] * ((fConst92 * fRec0[0]) + fConst91)) + (fConst0 * ((fRec1[0] * (((fRec0[0] * (fConst90 + (fConst89 * fRec0[0]))) + (fRec1[0] * ((fRec0[0] * (fConst88 + (fConst87 * fRec0[0]))) + fConst86))) + fConst85)) + fConst84))))) + (fRec2[2] * (6.32838466389946e-09 + ((fRec0[0] * ((fConst83 * fRec0[0]) + fConst82)) + (fConst0 * ((fRec1[0] * (((fRec0[0] * (fConst81 + (fConst80 * fRec0[0]))) + (fRec1[0] * ((fRec0[0] * (fConst79 + (fConst78 * fRec0[0]))) + fConst77))) + fConst76)) + fConst75)))))) + (fRec2[3] * (6.32838466389946e-09 + ((fRec0[0] * ((fConst74 * fRec0[0]) + fConst72)) + (fConst0 * ((fRec1[0] * (((fRec0[0] * (fConst70 + (fConst68 * fRec0[0]))) + (fRec1[0] * ((fRec0[0] * (fConst66 + (fConst64 * fRec0[0]))) + fConst62))) + fConst60)) + fConst58)))))) + (fRec2[4] * (3.16419233194973e-09 + ((fRec0[0] * ((fConst56 * fRec0[0]) + fConst54)) + (fConst0 * ((fRec1[0] * (((fRec0[0] * (fConst52 + (fConst50 * fRec0[0]))) + (fRec1[0] * ((fRec0[0] * (fConst48 + (fConst46 * fRec0[0]))) + fConst45))) + fConst43)) + fConst41)))))) + (fRec2[5] * (6.32838466389946e-10 + ((fRec0[0] * ((fConst39 * fRec0[0]) + fConst38)) + (fConst0 * ((fRec1[0] * (((fRec0[0] * (fConst37 + (fConst36 * fRec0[0]))) + (fRec1[0] * ((fRec0[0] * (fConst35 + (fConst34 * fRec0[0]))) + fConst33))) + fConst32)) + fConst31)))))) / fTemp0));
		fRec3[0] = ((0.993 * fRec3[1]) + fSlow2);
		output0[i] = (FAUSTFLOAT)(fConst0 * ((fRec3[0] * ((((((fRec2[0] * (((fRec0[0] * (fConst132 + (fConst131 * fRec0[0]))) + (fConst0 * (fRec1[0] * (fConst130 + (fRec0[0] * (fConst129 + (fConst128 * fRec0[0]))))))) + fConst127)) + (fRec2[1] * (((fRec0[0] * (fConst126 + (fConst125 * fRec0[0]))) + (fConst0 * (fRec1[0] * (fConst124 + (fRec0[0] * (fConst123 + (fConst122 * fRec0[0]))))))) + fConst121))) + (fRec2[2] * (((fRec0[0] * (fConst120 + (fConst119 * fRec0[0]))) + (fConst0 * (fRec1[0] * (fConst118 + (fRec0[0] * (fConst117 + (fConst116 * fRec0[0]))))))) + fConst115))) + (fRec2[3] * (((fRec0[0] * (fConst114 + (fConst112 * fRec0[0]))) + (fConst0 * (fRec1[0] * (fConst110 + (fRec0[0] * (fConst108 + (fConst106 * fRec0[0]))))))) + fConst104))) + (fRec2[4] * (((fRec0[0] * (fConst103 + (fConst101 * fRec0[0]))) + (fConst0 * (fRec1[0] * (fConst100 + (fRec0[0] * (fConst98 + (fConst96 * fRec0[0]))))))) + fConst94))) + (fRec2[5] * (((fRec0[0] * (fConst30 + (fConst28 * fRec0[0]))) + (fConst0 * (fRec1[0] * (fConst26 + (fRec0[0] * (fConst24 + (fConst22 * fRec0[0]))))))) + fConst20)))) / fTemp0));
		// post processing
		fRec3[1] = fRec3[0];
		for (int i=5; i>0; i--) fRec2[i] = fRec2[i-1];
		fRec1[1] = fRec1[0];
		fRec0[1] = fRec0[0];
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

} // end namespace mbr1on
