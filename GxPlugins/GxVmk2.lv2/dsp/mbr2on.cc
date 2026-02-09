// generated from file './/mbr2on.dsp' by dsp2cc:
// Code generated with Faust 0.9.73 (http://faust.grame.fr)


namespace mbr2on {

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
	name = N_("MBR2ON");
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
	fConst1 = (1.12999012445903e-25 * fConst0);
	fConst2 = (2.66484219976024e-11 + (fConst0 * (4.41618359682262e-14 + (fConst0 * (7.48045274057643e-18 + (fConst0 * (1.10698090525809e-21 + fConst1)))))));
	fConst3 = (3.68475040584466e-27 * fConst0);
	fConst4 = (5.57830269773706e-14 + (fConst0 * (5.02968430397797e-16 + (fConst0 * (7.11566245039781e-19 + (fConst0 * (1.0867966613683e-22 + fConst3)))))));
	fConst5 = (4.09416711760518e-27 * fConst0);
	fConst6 = ((fConst0 * ((fConst0 * ((fConst0 * (0 - (1.23029721884036e-22 + fConst5))) - 7.45138415404143e-19)) - 1.49437099792589e-16)) - 5.11770889700648e-15);
	fConst7 = (4.09416711760518e-25 * fConst0);
	fConst8 = (fConst0 * (1.12589595734143e-14 + (fConst0 * (7.41044248286538e-17 + (fConst0 * (1.23234430239916e-20 + fConst7))))));
	fConst9 = (4.05322544642913e-25 * fConst0);
	fConst10 = ((fConst0 * ((fConst0 * ((fConst0 * (0 - (1.22210888460515e-20 + fConst9))) - 7.39815998151256e-17)) - 1.48413558013188e-14)) - 5.11770889700648e-13);
	fConst11 = (3.27533369408415e-25 * fConst0);
	fConst12 = ((fConst0 * ((fConst0 * ((fConst0 * (0 - (1.17052237892332e-20 + fConst11))) - 7.81576502750829e-17)) - 4.80041094539208e-14)) - 5.11770889700648e-12);
	fConst13 = (3.2384861900257e-25 * fConst0);
	fConst14 = (5.57830269773706e-12 + (fConst0 * (5.12282660590348e-14 + (fConst0 * (7.80471077629076e-17 + (fConst0 * (1.16131050290871e-20 + fConst13)))))));
	fConst15 = (1.22513856827217e-23 * fConst0);
	fConst16 = (2.84032843783859e-07 + (fConst0 * (2.7103898089436e-09 + (fConst0 * (4.75547746127636e-12 + (fConst0 * (8.06548875084662e-16 + (fConst0 * (1.19377724815132e-19 + fConst15)))))))));
	fConst17 = (1.23643846951676e-23 * fConst0);
	fConst18 = ((fConst0 * ((fConst0 * ((fConst0 * ((fConst0 * (0 - (1.19860836535009e-19 + fConst17))) - 8.08250001522027e-16)) - 4.76131164941895e-12)) - 2.51330683931988e-09)) - 2.55885444850324e-07);
	fConst19 = (1.0235417794013e-26 * fConst0);
	fConst20 = ((fConst0 * (2.58444299298827e-15 + (fConst0 * ((fConst0 * (1.0286594882983e-22 - fConst19)) - 2.63562008195834e-19)))) - 1.27942722425162e-11);
	fConst21 = (1.0235417794013e-23 * fConst0);
	fConst22 = ((fConst0 * (1.0235417794013e-17 + (fConst0 * (fConst21 - 5.22006307494661e-20)))) - 2.55885444850324e-14);
	fConst23 = (1.01330636160728e-23 * fConst0);
	fConst24 = (2.55885444850324e-14 + (fConst0 * ((fConst0 * (5.22006307494661e-20 - fConst23)) - 1.27942722425162e-17)));
	fConst25 = (1.0235417794013e-25 * fConst0);
	fConst26 = (2.55885444850324e-16 + (fConst0 * ((fConst0 * (5.16888598597654e-22 - fConst25)) - 7.67656334550972e-20)));
	fConst27 = (2.04708355880259e-24 * fConst0);
	fConst28 = (1.27942722425162e-09 + (fConst0 * ((fConst0 * (7.77891752344985e-17 + (fConst0 * (fConst27 - 1.54554808689596e-20)))) - 5.14329744149151e-13)));
	fConst29 = (2.03684814100858e-24 * fConst0);
	fConst30 = ((fConst0 * (5.14329744149151e-13 + (fConst0 * ((fConst0 * (1.54554808689596e-20 - fConst29)) - 7.80450606793488e-17)))) - 1.27942722425162e-09);
	fConst31 = ((fConst0 * (4.41618359682262e-14 + (fConst0 * ((fConst0 * (1.10698090525809e-21 - fConst1)) - 7.48045274057643e-18)))) - 2.66484219976024e-11);
	fConst32 = ((fConst0 * (5.02968430397797e-16 + (fConst0 * ((fConst0 * (1.0867966613683e-22 - fConst3)) - 7.11566245039781e-19)))) - 5.57830269773706e-14);
	fConst33 = (5.11770889700648e-15 + (fConst0 * ((fConst0 * (7.45138415404143e-19 + (fConst0 * (fConst5 - 1.23029721884036e-22)))) - 1.49437099792589e-16)));
	fConst34 = (fConst0 * (1.12589595734143e-14 + (fConst0 * ((fConst0 * (1.23234430239916e-20 - fConst7)) - 7.41044248286538e-17))));
	fConst35 = (5.11770889700648e-13 + (fConst0 * ((fConst0 * (7.39815998151256e-17 + (fConst0 * (fConst9 - 1.22210888460515e-20)))) - 1.48413558013188e-14)));
	fConst36 = (5.11770889700648e-12 + (fConst0 * ((fConst0 * (7.81576502750829e-17 + (fConst0 * (fConst11 - 1.17052237892332e-20)))) - 4.80041094539208e-14)));
	fConst37 = ((fConst0 * (5.12282660590348e-14 + (fConst0 * ((fConst0 * (1.16131050290871e-20 - fConst13)) - 7.80471077629076e-17)))) - 5.57830269773706e-12);
	fConst38 = (2.84032843783859e-07 + (fConst0 * ((fConst0 * (4.75547746127636e-12 + (fConst0 * ((fConst0 * (1.19377724815132e-19 - fConst15)) - 8.06548875084662e-16)))) - 2.7103898089436e-09)));
	fConst39 = ((fConst0 * (2.51330683931988e-09 + (fConst0 * ((fConst0 * (8.08250001522027e-16 + (fConst0 * (fConst17 - 1.19860836535009e-19)))) - 4.76131164941895e-12)))) - 2.55885444850324e-07);
	fConst40 = (5.64995062229515e-25 * fConst0);
	fConst41 = ((fConst0 * (4.41618359682262e-14 + (fConst0 * (7.48045274057643e-18 + (fConst0 * (fConst40 - 3.32094271577427e-21)))))) - 7.99452659928073e-11);
	fConst42 = (1.84237520292233e-26 * fConst0);
	fConst43 = ((fConst0 * (5.02968430397797e-16 + (fConst0 * (7.11566245039781e-19 + (fConst0 * (fConst42 - 3.26038998410489e-22)))))) - 1.67349080932112e-13);
	fConst44 = (2.04708355880259e-26 * fConst0);
	fConst45 = (1.53531266910194e-14 + (fConst0 * ((fConst0 * ((fConst0 * (3.69089165652107e-22 - fConst44)) - 7.45138415404143e-19)) - 1.49437099792589e-16)));
	fConst46 = (fConst0 * (1.12589595734143e-14 + (fConst0 * (7.41044248286538e-17 + (fConst0 * (fConst27 - 3.69703290719748e-20))))));
	fConst47 = (2.02661272321456e-24 * fConst0);
	fConst48 = (1.53531266910194e-12 + (fConst0 * ((fConst0 * ((fConst0 * (3.66632665381544e-20 - fConst47)) - 7.39815998151256e-17)) - 1.48413558013188e-14)));
	fConst49 = (1.63766684704207e-24 * fConst0);
	fConst50 = (1.53531266910194e-11 + (fConst0 * ((fConst0 * ((fConst0 * (3.51156713676996e-20 - fConst49)) - 7.81576502750829e-17)) - 4.80041094539208e-14)));
	fConst51 = (1.61924309501285e-24 * fConst0);
	fConst52 = ((fConst0 * (5.12282660590348e-14 + (fConst0 * (7.80471077629076e-17 + (fConst0 * (fConst51 - 3.48393150872613e-20)))))) - 1.67349080932112e-11);
	fConst53 = (6.12569284136087e-23 * fConst0);
	fConst54 = (1.4201642189193e-06 + (fConst0 * ((fConst0 * (4.75547746127636e-12 + (fConst0 * (8.06548875084662e-16 + (fConst0 * (fConst53 - 3.58133174445396e-19)))))) - 8.1311694268308e-09)));
	fConst55 = (6.18219234758382e-23 * fConst0);
	fConst56 = ((fConst0 * (7.53992051795964e-09 + (fConst0 * ((fConst0 * ((fConst0 * (3.59582509605028e-19 - fConst55)) - 8.08250001522027e-16)) - 4.76131164941895e-12)))) - 1.27942722425162e-06);
	fConst57 = (1.12999012445903e-24 * fConst0);
	fConst58 = ((fConst0 * ((fConst0 * (1.49609054811529e-17 + (fConst0 * (2.21396181051618e-21 - fConst57)))) - 8.83236719364525e-14)) - 5.32968439952049e-11);
	fConst59 = (3.68475040584466e-26 * fConst0);
	fConst60 = ((fConst0 * ((fConst0 * (1.42313249007956e-18 + (fConst0 * (2.17359332273659e-22 - fConst59)))) - 1.00593686079559e-15)) - 1.11566053954741e-13);
	fConst61 = (4.09416711760518e-26 * fConst0);
	fConst62 = (1.0235417794013e-14 + (fConst0 * (2.98874199585178e-16 + (fConst0 * ((fConst0 * (fConst61 - 2.46059443768071e-22)) - 1.49027683080829e-18)))));
	fConst63 = (4.09416711760518e-24 * fConst0);
	fConst64 = (fConst0 * ((fConst0 * (1.48208849657308e-16 + (fConst0 * (2.46468860479832e-20 - fConst63)))) - 2.25179191468285e-14));
	fConst65 = (4.05322544642913e-24 * fConst0);
	fConst66 = (1.0235417794013e-12 + (fConst0 * (2.96827116026376e-14 + (fConst0 * ((fConst0 * (fConst65 - 2.44421776921029e-20)) - 1.47963199630251e-16)))));
	fConst67 = (3.27533369408415e-24 * fConst0);
	fConst68 = (1.0235417794013e-11 + (fConst0 * (9.60082189078415e-14 + (fConst0 * ((fConst0 * (fConst67 - 2.34104475784664e-20)) - 1.56315300550166e-16)))));
	fConst69 = (3.2384861900257e-24 * fConst0);
	fConst70 = ((fConst0 * ((fConst0 * (1.56094215525815e-16 + (fConst0 * (2.32262100581742e-20 - fConst69)))) - 1.0245653211807e-13)) - 1.11566053954741e-11);
	fConst71 = (1.22513856827217e-22 * fConst0);
	fConst72 = (2.84032843783859e-06 + (fConst0 * ((fConst0 * ((fConst0 * (1.61309775016932e-15 + (fConst0 * (2.38755449630264e-19 - fConst71)))) - 9.51095492255272e-12)) - 5.4207796178872e-09)));
	fConst73 = (1.23643846951676e-22 * fConst0);
	fConst74 = ((fConst0 * (5.02661367863976e-09 + (fConst0 * (9.52262329883789e-12 + (fConst0 * ((fConst0 * (fConst73 - 2.39721673070019e-19)) - 1.61650000304405e-15)))))) - 2.55885444850324e-06);
	fConst75 = (5.32968439952049e-11 + (fConst0 * ((fConst0 * ((fConst0 * (2.21396181051618e-21 + fConst57)) - 1.49609054811529e-17)) - 8.83236719364525e-14)));
	fConst76 = (1.11566053954741e-13 + (fConst0 * ((fConst0 * ((fConst0 * (2.17359332273659e-22 + fConst59)) - 1.42313249007956e-18)) - 1.00593686079559e-15)));
	fConst77 = ((fConst0 * (2.98874199585178e-16 + (fConst0 * (1.49027683080829e-18 + (fConst0 * (0 - (2.46059443768071e-22 + fConst61))))))) - 1.0235417794013e-14);
	fConst78 = (fConst0 * ((fConst0 * ((fConst0 * (2.46468860479832e-20 + fConst63)) - 1.48208849657308e-16)) - 2.25179191468285e-14));
	fConst79 = ((fConst0 * (2.96827116026376e-14 + (fConst0 * (1.47963199630251e-16 + (fConst0 * (0 - (2.44421776921029e-20 + fConst65))))))) - 1.0235417794013e-12);
	fConst80 = ((fConst0 * (9.60082189078415e-14 + (fConst0 * (1.56315300550166e-16 + (fConst0 * (0 - (2.34104475784664e-20 + fConst67))))))) - 1.0235417794013e-11);
	fConst81 = (1.11566053954741e-11 + (fConst0 * ((fConst0 * ((fConst0 * (2.32262100581742e-20 + fConst69)) - 1.56094215525815e-16)) - 1.0245653211807e-13)));
	fConst82 = (2.84032843783859e-06 + (fConst0 * (5.4207796178872e-09 + (fConst0 * ((fConst0 * ((fConst0 * (2.38755449630264e-19 + fConst71)) - 1.61309775016932e-15)) - 9.51095492255272e-12)))));
	fConst83 = ((fConst0 * ((fConst0 * (9.52262329883789e-12 + (fConst0 * (1.61650000304405e-15 + (fConst0 * (0 - (2.39721673070019e-19 + fConst73))))))) - 5.02661367863976e-09)) - 2.55885444850324e-06);
	fConst84 = (7.99452659928073e-11 + (fConst0 * (4.41618359682262e-14 + (fConst0 * ((fConst0 * (0 - (3.32094271577427e-21 + fConst40))) - 7.48045274057643e-18)))));
	fConst85 = (1.67349080932112e-13 + (fConst0 * (5.02968430397797e-16 + (fConst0 * ((fConst0 * (0 - (3.26038998410489e-22 + fConst42))) - 7.11566245039781e-19)))));
	fConst86 = ((fConst0 * ((fConst0 * (7.45138415404143e-19 + (fConst0 * (3.69089165652107e-22 + fConst44)))) - 1.49437099792589e-16)) - 1.53531266910194e-14);
	fConst87 = (fConst0 * (1.12589595734143e-14 + (fConst0 * ((fConst0 * (0 - (3.69703290719748e-20 + fConst27))) - 7.41044248286538e-17))));
	fConst88 = ((fConst0 * ((fConst0 * (7.39815998151256e-17 + (fConst0 * (3.66632665381544e-20 + fConst47)))) - 1.48413558013188e-14)) - 1.53531266910194e-12);
	fConst89 = ((fConst0 * ((fConst0 * (7.81576502750829e-17 + (fConst0 * (3.51156713676996e-20 + fConst49)))) - 4.80041094539208e-14)) - 1.53531266910194e-11);
	fConst90 = (1.67349080932112e-11 + (fConst0 * (5.12282660590348e-14 + (fConst0 * ((fConst0 * (0 - (3.48393150872613e-20 + fConst51))) - 7.80471077629076e-17)))));
	fConst91 = (1.4201642189193e-06 + (fConst0 * (8.1311694268308e-09 + (fConst0 * (4.75547746127636e-12 + (fConst0 * ((fConst0 * (0 - (3.58133174445396e-19 + fConst53))) - 8.06548875084662e-16)))))));
	fConst92 = ((fConst0 * ((fConst0 * ((fConst0 * (8.08250001522027e-16 + (fConst0 * (3.59582509605028e-19 + fConst55)))) - 4.76131164941895e-12)) - 7.53992051795964e-09)) - 1.27942722425162e-06);
	fConst93 = (5.11770889700648e-26 * fConst0);
	fConst94 = ((fConst0 * (2.58444299298827e-15 + (fConst0 * (2.63562008195834e-19 + (fConst0 * (fConst93 - 3.08597846489491e-22)))))) - 3.83828167275486e-11);
	fConst95 = (5.11770889700648e-23 * fConst0);
	fConst96 = ((fConst0 * ((fConst0 * (1.56601892248398e-19 - fConst95)) - 1.0235417794013e-17)) - 2.55885444850324e-14);
	fConst97 = (5.06653180803641e-23 * fConst0);
	fConst98 = (2.55885444850324e-14 + (fConst0 * (1.27942722425162e-17 + (fConst0 * (fConst97 - 1.56601892248398e-19)))));
	fConst99 = (5.11770889700648e-25 * fConst0);
	fConst100 = (2.55885444850324e-16 + (fConst0 * (7.67656334550972e-20 + (fConst0 * (fConst99 - 1.55066579579296e-21)))));
	fConst101 = (3.83828167275486e-09 + (fConst0 * ((fConst0 * ((fConst0 * (4.63664426068787e-20 - fConst21)) - 7.77891752344985e-17)) - 5.14329744149151e-13)));
	fConst102 = (1.01842407050429e-23 * fConst0);
	fConst103 = ((fConst0 * (5.14329744149151e-13 + (fConst0 * (7.80450606793488e-17 + (fConst0 * (fConst102 - 4.63664426068787e-20)))))) - 3.83828167275486e-09);
	fConst104 = ((fConst0 * ((fConst0 * (5.27124016391667e-19 + (fConst0 * (2.0573189765966e-22 - fConst25)))) - 5.16888598597654e-15)) - 2.55885444850324e-11);
	fConst105 = (1.0235417794013e-22 * fConst0);
	fConst106 = (5.11770889700648e-14 + (fConst0 * ((fConst0 * (fConst105 - 1.04401261498932e-19)) - 2.04708355880259e-17)));
	fConst107 = (1.01330636160728e-22 * fConst0);
	fConst108 = ((fConst0 * (2.55885444850324e-17 + (fConst0 * (1.04401261498932e-19 - fConst107)))) - 5.11770889700648e-14);
	fConst109 = (1.0235417794013e-24 * fConst0);
	fConst110 = ((fConst0 * (1.53531266910194e-19 + (fConst0 * (1.03377719719531e-21 - fConst109)))) - 5.11770889700648e-16);
	fConst111 = (2.04708355880259e-23 * fConst0);
	fConst112 = (2.55885444850324e-09 + (fConst0 * (1.0286594882983e-12 + (fConst0 * ((fConst0 * (fConst111 - 3.09109617379191e-20)) - 1.55578350468997e-16)))));
	fConst113 = (2.03684814100858e-23 * fConst0);
	fConst114 = ((fConst0 * ((fConst0 * (1.56090121358698e-16 + (fConst0 * (3.09109617379191e-20 - fConst113)))) - 1.0286594882983e-12)) - 2.55885444850324e-09);
	fConst115 = (2.55885444850324e-11 + (fConst0 * ((fConst0 * ((fConst0 * (2.0573189765966e-22 + fConst25)) - 5.27124016391667e-19)) - 5.16888598597654e-15)));
	fConst116 = (5.11770889700648e-14 + (fConst0 * (2.04708355880259e-17 + (fConst0 * (0 - (1.04401261498932e-19 + fConst105))))));
	fConst117 = ((fConst0 * ((fConst0 * (1.04401261498932e-19 + fConst107)) - 2.55885444850324e-17)) - 5.11770889700648e-14);
	fConst118 = ((fConst0 * ((fConst0 * (1.03377719719531e-21 + fConst109)) - 1.53531266910194e-19)) - 5.11770889700648e-16);
	fConst119 = ((fConst0 * (1.0286594882983e-12 + (fConst0 * (1.55578350468997e-16 + (fConst0 * (0 - (3.09109617379191e-20 + fConst111))))))) - 2.55885444850324e-09);
	fConst120 = (2.55885444850324e-09 + (fConst0 * ((fConst0 * ((fConst0 * (3.09109617379191e-20 + fConst113)) - 1.56090121358698e-16)) - 1.0286594882983e-12)));
	fConst121 = (3.83828167275486e-11 + (fConst0 * (2.58444299298827e-15 + (fConst0 * ((fConst0 * (0 - (3.08597846489491e-22 + fConst93))) - 2.63562008195834e-19)))));
	fConst122 = ((fConst0 * (1.0235417794013e-17 + (fConst0 * (1.56601892248398e-19 + fConst95)))) - 2.55885444850324e-14);
	fConst123 = (2.55885444850324e-14 + (fConst0 * ((fConst0 * (0 - (1.56601892248398e-19 + fConst97))) - 1.27942722425162e-17)));
	fConst124 = (2.55885444850324e-16 + (fConst0 * ((fConst0 * (0 - (1.55066579579296e-21 + fConst99))) - 7.67656334550972e-20)));
	fConst125 = ((fConst0 * ((fConst0 * (7.77891752344985e-17 + (fConst0 * (4.63664426068787e-20 + fConst21)))) - 5.14329744149151e-13)) - 3.83828167275486e-09);
	fConst126 = (3.83828167275486e-09 + (fConst0 * (5.14329744149151e-13 + (fConst0 * ((fConst0 * (0 - (4.63664426068787e-20 + fConst102))) - 7.80450606793488e-17)))));
	fConst127 = (1.27942722425162e-11 + (fConst0 * (2.58444299298827e-15 + (fConst0 * (2.63562008195834e-19 + (fConst0 * (1.0286594882983e-22 + fConst19)))))));
	fConst128 = ((fConst0 * ((fConst0 * (0 - (5.22006307494661e-20 + fConst21))) - 1.0235417794013e-17)) - 2.55885444850324e-14);
	fConst129 = (2.55885444850324e-14 + (fConst0 * (1.27942722425162e-17 + (fConst0 * (5.22006307494661e-20 + fConst23)))));
	fConst130 = (2.55885444850324e-16 + (fConst0 * (7.67656334550972e-20 + (fConst0 * (5.16888598597654e-22 + fConst25)))));
	fConst131 = ((fConst0 * ((fConst0 * ((fConst0 * (0 - (1.54554808689596e-20 + fConst27))) - 7.77891752344985e-17)) - 5.14329744149151e-13)) - 1.27942722425162e-09);
	fConst132 = (1.27942722425162e-09 + (fConst0 * (5.14329744149151e-13 + (fConst0 * (7.80450606793488e-17 + (fConst0 * (1.54554808689596e-20 + fConst29)))))));
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
		double fTemp0 = (2.84032843783859e-09 + ((fRec0[0] * ((fConst18 * fRec0[0]) + fConst16)) + (fConst0 * ((fRec1[0] * (((fRec0[0] * (fConst14 + (fConst12 * fRec0[0]))) + (fRec1[0] * ((fRec0[0] * (fConst10 + (fConst8 * fRec0[0]))) + fConst6))) + fConst4)) + fConst2))));
		fRec2[0] = ((double)input0[i] - ((((((fRec2[1] * (1.4201642189193e-08 + ((fRec0[0] * ((fConst92 * fRec0[0]) + fConst91)) + (fConst0 * ((fRec1[0] * (((fRec0[0] * (fConst90 + (fConst89 * fRec0[0]))) + (fRec1[0] * ((fRec0[0] * (fConst88 + (fConst87 * fRec0[0]))) + fConst86))) + fConst85)) + fConst84))))) + (fRec2[2] * (2.8403284378386e-08 + ((fRec0[0] * ((fConst83 * fRec0[0]) + fConst82)) + (fConst0 * ((fRec1[0] * (((fRec0[0] * (fConst81 + (fConst80 * fRec0[0]))) + (fRec1[0] * ((fRec0[0] * (fConst79 + (fConst78 * fRec0[0]))) + fConst77))) + fConst76)) + fConst75)))))) + (fRec2[3] * (2.8403284378386e-08 + ((fRec0[0] * ((fConst74 * fRec0[0]) + fConst72)) + (fConst0 * ((fRec1[0] * (((fRec0[0] * (fConst70 + (fConst68 * fRec0[0]))) + (fRec1[0] * ((fRec0[0] * (fConst66 + (fConst64 * fRec0[0]))) + fConst62))) + fConst60)) + fConst58)))))) + (fRec2[4] * (1.4201642189193e-08 + ((fRec0[0] * ((fConst56 * fRec0[0]) + fConst54)) + (fConst0 * ((fRec1[0] * (((fRec0[0] * (fConst52 + (fConst50 * fRec0[0]))) + (fRec1[0] * ((fRec0[0] * (fConst48 + (fConst46 * fRec0[0]))) + fConst45))) + fConst43)) + fConst41)))))) + (fRec2[5] * (2.84032843783859e-09 + ((fRec0[0] * ((fConst39 * fRec0[0]) + fConst38)) + (fConst0 * ((fRec1[0] * (((fRec0[0] * (fConst37 + (fConst36 * fRec0[0]))) + (fRec1[0] * ((fRec0[0] * (fConst35 + (fConst34 * fRec0[0]))) + fConst33))) + fConst32)) + fConst31)))))) / fTemp0));
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

} // end namespace mbr2on
