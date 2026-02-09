// generated from file './/mbron.dsp' by dsp2cc:
// Code generated with Faust 0.9.73 (http://faust.grame.fr)


namespace mbron {

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
	name = N_("MBRON");
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
	fConst1 = (1.1952912389216e-25 * fConst0);
	fConst2 = (1.28697551008889e-12 + (fConst0 * (2.23301151733682e-15 + (fConst0 * (9.77069878100369e-19 + (fConst0 * (9.43587156290722e-22 + fConst1)))))));
	fConst3 = (3.89768882257045e-27 * fConst0);
	fConst4 = (5.90066780083582e-14 + (fConst0 * (5.32034524280866e-16 + (fConst0 * (7.52687019291938e-19 + (fConst0 * (1.14960166439036e-22 + fConst3)))))));
	fConst5 = (4.33076535841161e-27 * fConst0);
	fConst6 = ((fConst0 * ((fConst0 * ((fConst0 * (0 - (1.30139499020269e-22 + fConst5))) - 7.88199295230913e-19)) - 1.58072935582024e-16)) - 5.41345669801451e-15);
	fConst7 = (4.33076535841161e-25 * fConst0);
	fConst8 = (fConst0 * (1.19096047356319e-14 + (fConst0 * (7.83868529872501e-17 + (fConst0 * (1.30356037288189e-20 + fConst7))))));
	fConst9 = (4.28745770482749e-25 * fConst0);
	fConst10 = ((fConst0 * ((fConst0 * ((fConst0 * (0 - (1.29273345948587e-20 + fConst9))) - 7.82569300264978e-17)) - 1.56990244242421e-14)) - 5.41345669801451e-13);
	fConst11 = (3.46461228672929e-25 * fConst0);
	fConst12 = ((fConst0 * ((fConst0 * ((fConst0 * (0 - (1.23816581596988e-20 + fConst11))) - 8.26743106920776e-17)) - 5.07782238273761e-14)) - 5.41345669801451e-12);
	fConst13 = (3.42563539850358e-25 * fConst0);
	fConst14 = (5.90066780083582e-12 + (fConst0 * (5.41887015471253e-14 + (fConst0 * (8.25573800274005e-17 + (fConst0 * (1.22842159391345e-20 + fConst13)))))));
	fConst15 = (1.29593822585109e-23 * fConst0);
	fConst16 = (1.36566748518093e-08 + (fConst0 * (1.30887540309449e-10 + (fConst0 * (2.39707862588083e-13 + (fConst0 * (1.02130077211771e-16 + (fConst0 * (1.01700347176434e-19 + fConst15)))))))));
	fConst17 = (1.30789113824031e-23 * fConst0);
	fConst18 = ((fConst0 * ((fConst0 * ((fConst0 * ((fConst0 * (0 - (1.0198401230741e-19 + fConst17))) - 9.82453806852758e-17)) - 2.39058247784321e-13)) - 1.21359856520944e-10)) - 1.23033106773057e-08);
	fConst19 = (1.0826913396029e-26 * fConst0);
	fConst20 = ((fConst0 * (1.5010039026313e-16 + (fConst0 * ((fConst0 * (1.08810479630092e-22 - fConst19)) - 2.78793019947747e-19)))) - 6.15165533865286e-13);
	fConst21 = (1.0826913396029e-23 * fConst0);
	fConst22 = ((fConst0 * (1.0826913396029e-17 + (fConst0 * (fConst21 - 5.5217258319748e-20)))) - 2.70672834900726e-14);
	fConst23 = (1.07186442620687e-23 * fConst0);
	fConst24 = (2.70672834900726e-14 + (fConst0 * ((fConst0 * (5.5217258319748e-20 - fConst23)) - 1.35336417450363e-17)));
	fConst25 = (1.0826913396029e-25 * fConst0);
	fConst26 = (2.70672834900726e-16 + (fConst0 * ((fConst0 * (5.46759126499466e-22 - fConst25)) - 8.12018504702177e-20)));
	fConst27 = (2.16538267920581e-24 * fConst0);
	fConst28 = (6.15165533865286e-11 + (fConst0 * ((fConst0 * (3.06106369651366e-17 + (fConst0 * (fConst27 - 1.63486392280038e-20)))) - 2.73133497036187e-14)));
	fConst29 = (2.15455576580978e-24 * fConst0);
	fConst30 = ((fConst0 * (2.73133497036187e-14 + (fConst0 * ((fConst0 * (1.63486392280038e-20 - fConst29)) - 3.08813098000373e-17)))) - 6.15165533865286e-11);
	fConst31 = ((fConst0 * (2.23301151733682e-15 + (fConst0 * ((fConst0 * (9.43587156290722e-22 - fConst1)) - 9.77069878100369e-19)))) - 1.28697551008889e-12);
	fConst32 = ((fConst0 * (5.32034524280866e-16 + (fConst0 * ((fConst0 * (1.14960166439036e-22 - fConst3)) - 7.52687019291938e-19)))) - 5.90066780083582e-14);
	fConst33 = (5.41345669801451e-15 + (fConst0 * ((fConst0 * (7.88199295230913e-19 + (fConst0 * (fConst5 - 1.30139499020269e-22)))) - 1.58072935582024e-16)));
	fConst34 = (fConst0 * (1.19096047356319e-14 + (fConst0 * ((fConst0 * (1.30356037288189e-20 - fConst7)) - 7.83868529872501e-17))));
	fConst35 = (5.41345669801451e-13 + (fConst0 * ((fConst0 * (7.82569300264978e-17 + (fConst0 * (fConst9 - 1.29273345948587e-20)))) - 1.56990244242421e-14)));
	fConst36 = (5.41345669801451e-12 + (fConst0 * ((fConst0 * (8.26743106920776e-17 + (fConst0 * (fConst11 - 1.23816581596988e-20)))) - 5.07782238273761e-14)));
	fConst37 = ((fConst0 * (5.41887015471253e-14 + (fConst0 * ((fConst0 * (1.22842159391345e-20 - fConst13)) - 8.25573800274005e-17)))) - 5.90066780083582e-12);
	fConst38 = (1.36566748518093e-08 + (fConst0 * ((fConst0 * (2.39707862588083e-13 + (fConst0 * ((fConst0 * (1.01700347176434e-19 - fConst15)) - 1.02130077211771e-16)))) - 1.30887540309449e-10)));
	fConst39 = ((fConst0 * (1.21359856520944e-10 + (fConst0 * ((fConst0 * (9.82453806852758e-17 + (fConst0 * (fConst17 - 1.0198401230741e-19)))) - 2.39058247784321e-13)))) - 1.23033106773057e-08);
	fConst40 = (5.97645619460802e-25 * fConst0);
	fConst41 = ((fConst0 * (2.23301151733682e-15 + (fConst0 * (9.77069878100369e-19 + (fConst0 * (fConst40 - 2.83076146887217e-21)))))) - 3.86092653026666e-12);
	fConst42 = (1.94884441128522e-26 * fConst0);
	fConst43 = ((fConst0 * (5.32034524280866e-16 + (fConst0 * (7.52687019291938e-19 + (fConst0 * (fConst42 - 3.44880499317109e-22)))))) - 1.77020034025075e-13);
	fConst44 = (2.16538267920581e-26 * fConst0);
	fConst45 = (1.62403700940435e-14 + (fConst0 * ((fConst0 * ((fConst0 * (3.90418497060807e-22 - fConst44)) - 7.88199295230913e-19)) - 1.58072935582024e-16)));
	fConst46 = (fConst0 * (1.19096047356319e-14 + (fConst0 * (7.83868529872501e-17 + (fConst0 * (fConst27 - 3.91068111864568e-20))))));
	fConst47 = (2.14372885241375e-24 * fConst0);
	fConst48 = (1.62403700940435e-12 + (fConst0 * ((fConst0 * ((fConst0 * (3.8782003784576e-20 - fConst47)) - 7.82569300264978e-17)) - 1.56990244242421e-14)));
	fConst49 = (1.73230614336464e-24 * fConst0);
	fConst50 = (1.62403700940435e-11 + (fConst0 * ((fConst0 * ((fConst0 * (3.71449744790964e-20 - fConst49)) - 8.26743106920776e-17)) - 5.07782238273761e-14)));
	fConst51 = (1.71281769925179e-24 * fConst0);
	fConst52 = ((fConst0 * (5.41887015471253e-14 + (fConst0 * (8.25573800274005e-17 + (fConst0 * (fConst51 - 3.68526478174036e-20)))))) - 1.77020034025075e-11);
	fConst53 = (6.47969112925545e-23 * fConst0);
	fConst54 = (6.82833742590467e-08 + (fConst0 * ((fConst0 * (2.39707862588083e-13 + (fConst0 * (1.02130077211771e-16 + (fConst0 * (fConst53 - 3.05101041529302e-19)))))) - 3.92662620928347e-10)));
	fConst55 = (6.53945569120153e-23 * fConst0);
	fConst56 = ((fConst0 * (3.64079569562831e-10 + (fConst0 * ((fConst0 * ((fConst0 * (3.0595203692223e-19 - fConst55)) - 9.82453806852758e-17)) - 2.39058247784321e-13)))) - 6.15165533865286e-08);
	fConst57 = (1.1952912389216e-24 * fConst0);
	fConst58 = ((fConst0 * ((fConst0 * (1.95413975620074e-18 + (fConst0 * (1.88717431258144e-21 - fConst57)))) - 4.46602303467364e-15)) - 2.57395102017777e-12);
	fConst59 = (3.89768882257045e-26 * fConst0);
	fConst60 = ((fConst0 * ((fConst0 * (1.50537403858388e-18 + (fConst0 * (2.29920332878072e-22 - fConst59)))) - 1.06406904856173e-15)) - 1.18013356016716e-13);
	fConst61 = (4.33076535841161e-26 * fConst0);
	fConst62 = (1.0826913396029e-14 + (fConst0 * (3.16145871164048e-16 + (fConst0 * ((fConst0 * (fConst61 - 2.60278998040538e-22)) - 1.57639859046183e-18)))));
	fConst63 = (4.33076535841161e-24 * fConst0);
	fConst64 = (fConst0 * ((fConst0 * (1.567737059745e-16 + (fConst0 * (2.60712074576379e-20 - fConst63)))) - 2.38192094712639e-14));
	fConst65 = (4.28745770482749e-24 * fConst0);
	fConst66 = (1.0826913396029e-12 + (fConst0 * (3.13980488484842e-14 + (fConst0 * ((fConst0 * (fConst65 - 2.58546691897173e-20)) - 1.56513860052996e-16)))));
	fConst67 = (3.46461228672929e-24 * fConst0);
	fConst68 = (1.0826913396029e-11 + (fConst0 * (1.01556447654752e-13 + (fConst0 * ((fConst0 * (fConst67 - 2.47633163193976e-20)) - 1.65348621384155e-16)))));
	fConst69 = (3.42563539850358e-24 * fConst0);
	fConst70 = ((fConst0 * ((fConst0 * (1.65114760054801e-16 + (fConst0 * (2.45684318782691e-20 - fConst69)))) - 1.08377403094251e-13)) - 1.18013356016716e-11);
	fConst71 = (1.29593822585109e-22 * fConst0);
	fConst72 = (1.36566748518093e-07 + (fConst0 * ((fConst0 * ((fConst0 * (2.04260154423542e-16 + (fConst0 * (2.03400694352868e-19 - fConst71)))) - 4.79415725176165e-13)) - 2.61775080618898e-10)));
	fConst73 = (1.30789113824031e-22 * fConst0);
	fConst74 = ((fConst0 * (2.42719713041887e-10 + (fConst0 * (4.78116495568642e-13 + (fConst0 * ((fConst0 * (fConst73 - 2.0396802461482e-19)) - 1.96490761370552e-16)))))) - 1.23033106773057e-07);
	fConst75 = (2.57395102017777e-12 + (fConst0 * ((fConst0 * ((fConst0 * (1.88717431258144e-21 + fConst57)) - 1.95413975620074e-18)) - 4.46602303467364e-15)));
	fConst76 = (1.18013356016716e-13 + (fConst0 * ((fConst0 * ((fConst0 * (2.29920332878072e-22 + fConst59)) - 1.50537403858388e-18)) - 1.06406904856173e-15)));
	fConst77 = ((fConst0 * (3.16145871164048e-16 + (fConst0 * (1.57639859046183e-18 + (fConst0 * (0 - (2.60278998040538e-22 + fConst61))))))) - 1.0826913396029e-14);
	fConst78 = (fConst0 * ((fConst0 * ((fConst0 * (2.60712074576379e-20 + fConst63)) - 1.567737059745e-16)) - 2.38192094712639e-14));
	fConst79 = ((fConst0 * (3.13980488484842e-14 + (fConst0 * (1.56513860052996e-16 + (fConst0 * (0 - (2.58546691897173e-20 + fConst65))))))) - 1.0826913396029e-12);
	fConst80 = ((fConst0 * (1.01556447654752e-13 + (fConst0 * (1.65348621384155e-16 + (fConst0 * (0 - (2.47633163193976e-20 + fConst67))))))) - 1.0826913396029e-11);
	fConst81 = (1.18013356016716e-11 + (fConst0 * ((fConst0 * ((fConst0 * (2.45684318782691e-20 + fConst69)) - 1.65114760054801e-16)) - 1.08377403094251e-13)));
	fConst82 = (1.36566748518093e-07 + (fConst0 * (2.61775080618898e-10 + (fConst0 * ((fConst0 * ((fConst0 * (2.03400694352868e-19 + fConst71)) - 2.04260154423542e-16)) - 4.79415725176165e-13)))));
	fConst83 = ((fConst0 * ((fConst0 * (4.78116495568642e-13 + (fConst0 * (1.96490761370552e-16 + (fConst0 * (0 - (2.0396802461482e-19 + fConst73))))))) - 2.42719713041887e-10)) - 1.23033106773057e-07);
	fConst84 = (3.86092653026666e-12 + (fConst0 * (2.23301151733682e-15 + (fConst0 * ((fConst0 * (0 - (2.83076146887217e-21 + fConst40))) - 9.77069878100369e-19)))));
	fConst85 = (1.77020034025075e-13 + (fConst0 * (5.32034524280866e-16 + (fConst0 * ((fConst0 * (0 - (3.44880499317109e-22 + fConst42))) - 7.52687019291938e-19)))));
	fConst86 = ((fConst0 * ((fConst0 * (7.88199295230913e-19 + (fConst0 * (3.90418497060807e-22 + fConst44)))) - 1.58072935582024e-16)) - 1.62403700940435e-14);
	fConst87 = (fConst0 * (1.19096047356319e-14 + (fConst0 * ((fConst0 * (0 - (3.91068111864568e-20 + fConst27))) - 7.83868529872501e-17))));
	fConst88 = ((fConst0 * ((fConst0 * (7.82569300264978e-17 + (fConst0 * (3.8782003784576e-20 + fConst47)))) - 1.56990244242421e-14)) - 1.62403700940435e-12);
	fConst89 = ((fConst0 * ((fConst0 * (8.26743106920776e-17 + (fConst0 * (3.71449744790964e-20 + fConst49)))) - 5.07782238273761e-14)) - 1.62403700940435e-11);
	fConst90 = (1.77020034025075e-11 + (fConst0 * (5.41887015471253e-14 + (fConst0 * ((fConst0 * (0 - (3.68526478174036e-20 + fConst51))) - 8.25573800274005e-17)))));
	fConst91 = (6.82833742590467e-08 + (fConst0 * (3.92662620928347e-10 + (fConst0 * (2.39707862588083e-13 + (fConst0 * ((fConst0 * (0 - (3.05101041529302e-19 + fConst53))) - 1.02130077211771e-16)))))));
	fConst92 = ((fConst0 * ((fConst0 * ((fConst0 * (9.82453806852758e-17 + (fConst0 * (3.0595203692223e-19 + fConst55)))) - 2.39058247784321e-13)) - 3.64079569562831e-10)) - 6.15165533865286e-08);
	fConst93 = (5.41345669801451e-26 * fConst0);
	fConst94 = ((fConst0 * (1.5010039026313e-16 + (fConst0 * (2.78793019947747e-19 + (fConst0 * (fConst93 - 3.26431438890275e-22)))))) - 1.84549660159586e-12);
	fConst95 = (5.41345669801451e-23 * fConst0);
	fConst96 = ((fConst0 * ((fConst0 * (1.65651774959244e-19 - fConst95)) - 1.0826913396029e-17)) - 2.70672834900726e-14);
	fConst97 = (5.35932213103437e-23 * fConst0);
	fConst98 = (2.70672834900726e-14 + (fConst0 * (1.35336417450363e-17 + (fConst0 * (fConst97 - 1.65651774959244e-19)))));
	fConst99 = (5.41345669801451e-25 * fConst0);
	fConst100 = (2.70672834900726e-16 + (fConst0 * (8.12018504702177e-20 + (fConst0 * (fConst99 - 1.6402773794984e-21)))));
	fConst101 = (1.84549660159586e-10 + (fConst0 * ((fConst0 * ((fConst0 * (4.90459176840115e-20 - fConst21)) - 3.06106369651366e-17)) - 2.73133497036187e-14)));
	fConst102 = (1.07727788290489e-23 * fConst0);
	fConst103 = ((fConst0 * (2.73133497036187e-14 + (fConst0 * (3.08813098000373e-17 + (fConst0 * (fConst102 - 4.90459176840115e-20)))))) - 1.84549660159586e-10);
	fConst104 = ((fConst0 * ((fConst0 * (5.57586039895495e-19 + (fConst0 * (2.17620959260183e-22 - fConst25)))) - 3.00200780526259e-16)) - 1.23033106773057e-12);
	fConst105 = (1.0826913396029e-22 * fConst0);
	fConst106 = (5.41345669801451e-14 + (fConst0 * ((fConst0 * (fConst105 - 1.10434516639496e-19)) - 2.16538267920581e-17)));
	fConst107 = (1.07186442620687e-22 * fConst0);
	fConst108 = ((fConst0 * (2.70672834900726e-17 + (fConst0 * (1.10434516639496e-19 - fConst107)))) - 5.41345669801451e-14);
	fConst109 = (1.0826913396029e-24 * fConst0);
	fConst110 = ((fConst0 * (1.62403700940435e-19 + (fConst0 * (1.09351825299893e-21 - fConst109)))) - 5.41345669801451e-16);
	fConst111 = (2.16538267920581e-23 * fConst0);
	fConst112 = (1.23033106773057e-10 + (fConst0 * (5.46266994072374e-14 + (fConst0 * ((fConst0 * (fConst111 - 3.26972784560077e-20)) - 6.12212739302732e-17)))));
	fConst113 = (2.15455576580978e-23 * fConst0);
	fConst114 = ((fConst0 * ((fConst0 * (6.17626196000747e-17 + (fConst0 * (3.26972784560077e-20 - fConst113)))) - 5.46266994072374e-14)) - 1.23033106773057e-10);
	fConst115 = (1.23033106773057e-12 + (fConst0 * ((fConst0 * ((fConst0 * (2.17620959260183e-22 + fConst25)) - 5.57586039895495e-19)) - 3.00200780526259e-16)));
	fConst116 = (5.41345669801451e-14 + (fConst0 * (2.16538267920581e-17 + (fConst0 * (0 - (1.10434516639496e-19 + fConst105))))));
	fConst117 = ((fConst0 * ((fConst0 * (1.10434516639496e-19 + fConst107)) - 2.70672834900726e-17)) - 5.41345669801451e-14);
	fConst118 = ((fConst0 * ((fConst0 * (1.09351825299893e-21 + fConst109)) - 1.62403700940435e-19)) - 5.41345669801451e-16);
	fConst119 = ((fConst0 * (5.46266994072374e-14 + (fConst0 * (6.12212739302732e-17 + (fConst0 * (0 - (3.26972784560077e-20 + fConst111))))))) - 1.23033106773057e-10);
	fConst120 = (1.23033106773057e-10 + (fConst0 * ((fConst0 * ((fConst0 * (3.26972784560077e-20 + fConst113)) - 6.17626196000747e-17)) - 5.46266994072374e-14)));
	fConst121 = (1.84549660159586e-12 + (fConst0 * (1.5010039026313e-16 + (fConst0 * ((fConst0 * (0 - (3.26431438890275e-22 + fConst93))) - 2.78793019947747e-19)))));
	fConst122 = ((fConst0 * (1.0826913396029e-17 + (fConst0 * (1.65651774959244e-19 + fConst95)))) - 2.70672834900726e-14);
	fConst123 = (2.70672834900726e-14 + (fConst0 * ((fConst0 * (0 - (1.65651774959244e-19 + fConst97))) - 1.35336417450363e-17)));
	fConst124 = (2.70672834900726e-16 + (fConst0 * ((fConst0 * (0 - (1.6402773794984e-21 + fConst99))) - 8.12018504702177e-20)));
	fConst125 = ((fConst0 * ((fConst0 * (3.06106369651366e-17 + (fConst0 * (4.90459176840115e-20 + fConst21)))) - 2.73133497036187e-14)) - 1.84549660159586e-10);
	fConst126 = (1.84549660159586e-10 + (fConst0 * (2.73133497036187e-14 + (fConst0 * ((fConst0 * (0 - (4.90459176840115e-20 + fConst102))) - 3.08813098000373e-17)))));
	fConst127 = (6.15165533865286e-13 + (fConst0 * (1.5010039026313e-16 + (fConst0 * (2.78793019947747e-19 + (fConst0 * (1.08810479630092e-22 + fConst19)))))));
	fConst128 = ((fConst0 * ((fConst0 * (0 - (5.5217258319748e-20 + fConst21))) - 1.0826913396029e-17)) - 2.70672834900726e-14);
	fConst129 = (2.70672834900726e-14 + (fConst0 * (1.35336417450363e-17 + (fConst0 * (5.5217258319748e-20 + fConst23)))));
	fConst130 = (2.70672834900726e-16 + (fConst0 * (8.12018504702177e-20 + (fConst0 * (5.46759126499466e-22 + fConst25)))));
	fConst131 = ((fConst0 * ((fConst0 * ((fConst0 * (0 - (1.63486392280038e-20 + fConst27))) - 3.06106369651366e-17)) - 2.73133497036187e-14)) - 6.15165533865286e-11);
	fConst132 = (6.15165533865286e-11 + (fConst0 * (2.73133497036187e-14 + (fConst0 * (3.08813098000373e-17 + (fConst0 * (1.63486392280038e-20 + fConst29)))))));
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
		double fTemp0 = (1.36566748518093e-10 + ((fRec0[0] * ((fConst18 * fRec0[0]) + fConst16)) + (fConst0 * ((fRec1[0] * (((fRec0[0] * (fConst14 + (fConst12 * fRec0[0]))) + (fRec1[0] * ((fRec0[0] * (fConst10 + (fConst8 * fRec0[0]))) + fConst6))) + fConst4)) + fConst2))));
		fRec2[0] = ((double)input0[i] - ((((((fRec2[1] * (6.82833742590467e-10 + ((fRec0[0] * ((fConst92 * fRec0[0]) + fConst91)) + (fConst0 * ((fRec1[0] * (((fRec0[0] * (fConst90 + (fConst89 * fRec0[0]))) + (fRec1[0] * ((fRec0[0] * (fConst88 + (fConst87 * fRec0[0]))) + fConst86))) + fConst85)) + fConst84))))) + (fRec2[2] * (1.36566748518093e-09 + ((fRec0[0] * ((fConst83 * fRec0[0]) + fConst82)) + (fConst0 * ((fRec1[0] * (((fRec0[0] * (fConst81 + (fConst80 * fRec0[0]))) + (fRec1[0] * ((fRec0[0] * (fConst79 + (fConst78 * fRec0[0]))) + fConst77))) + fConst76)) + fConst75)))))) + (fRec2[3] * (1.36566748518093e-09 + ((fRec0[0] * ((fConst74 * fRec0[0]) + fConst72)) + (fConst0 * ((fRec1[0] * (((fRec0[0] * (fConst70 + (fConst68 * fRec0[0]))) + (fRec1[0] * ((fRec0[0] * (fConst66 + (fConst64 * fRec0[0]))) + fConst62))) + fConst60)) + fConst58)))))) + (fRec2[4] * (6.82833742590467e-10 + ((fRec0[0] * ((fConst56 * fRec0[0]) + fConst54)) + (fConst0 * ((fRec1[0] * (((fRec0[0] * (fConst52 + (fConst50 * fRec0[0]))) + (fRec1[0] * ((fRec0[0] * (fConst48 + (fConst46 * fRec0[0]))) + fConst45))) + fConst43)) + fConst41)))))) + (fRec2[5] * (1.36566748518093e-10 + ((fRec0[0] * ((fConst39 * fRec0[0]) + fConst38)) + (fConst0 * ((fRec1[0] * (((fRec0[0] * (fConst37 + (fConst36 * fRec0[0]))) + (fRec1[0] * ((fRec0[0] * (fConst35 + (fConst34 * fRec0[0]))) + fConst33))) + fConst32)) + fConst31)))))) / fTemp0));
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

} // end namespace mbron
