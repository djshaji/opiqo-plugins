// generated from file './/mbr1.dsp' by dsp2cc:
// Code generated with Faust 0.9.73 (http://faust.grame.fr)


namespace mbr1 {

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
	double 	fRec2[5];
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
	name = N_("MBR1");
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
	for (int i=0; i<5; i++) fRec2[i] = 0;
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
	fConst1 = (5.09659284443651e-21 * fConst0);
	fConst2 = (2.90429276448603e-10 + (fConst0 * (4.74893268461376e-13 + (fConst0 * (6.74157594007769e-17 + fConst1)))));
	fConst3 = (1.66193244927277e-22 * fConst0);
	fConst4 = (5.0319621380759e-13 + (fConst0 * (2.58984473345007e-15 + (fConst0 * (5.73274365418592e-18 + fConst3)))));
	fConst5 = (1.84659161030308e-22 * fConst0);
	fConst6 = ((fConst0 * ((fConst0 * (0 - (6.47230359411231e-18 + fConst5))) - 1.33877891746973e-15)) - 4.61647902575771e-14);
	fConst7 = (1.84659161030308e-20 * fConst0);
	fConst8 = (fConst0 * (1.0156253856667e-13 + (fConst0 * (6.48153655216382e-16 + fConst7))));
	fConst9 = (1.82812569420005e-20 * fConst0);
	fConst10 = ((fConst0 * ((fConst0 * (0 - (6.42613880385473e-16 + fConst9))) - 1.32954595941822e-13)) - 4.61647902575771e-12);
	fConst11 = (1.47727328824247e-20 * fConst0);
	fConst12 = ((fConst0 * ((fConst0 * (0 - (6.01804205797775e-16 + fConst11))) - 2.39133613534249e-13)) - 4.61647902575771e-11);
	fConst13 = (1.46065396374974e-20 * fConst0);
	fConst14 = (5.0319621380759e-11 + (fConst0 * (2.67386465171886e-13 + (fConst0 * (5.96818408449956e-16 + fConst13)))));
	fConst15 = (5.52574073467095e-19 * fConst0);
	fConst16 = (3.10728327616692e-06 + (fConst0 * (2.95412127107681e-08 + (fConst0 * (5.11834981897011e-11 + (fConst0 * (7.28293766644376e-15 + fConst15)))))));
	fConst17 = (5.57670666311531e-19 * fConst0);
	fConst18 = ((fConst0 * ((fConst0 * ((fConst0 * (0 - (7.32221506288674e-15 + fConst17))) - 5.13010455324519e-11)) - 2.73960527750481e-08)) - 2.79935430285308e-06);
	fConst19 = (4.61647902575771e-22 * fConst0);
	fConst20 = ((fConst0 * (2.35440430313643e-14 + (fConst0 * (fConst19 - 6.94780093376535e-18)))) - 1.39967715142654e-10);
	fConst21 = (4.61647902575771e-19 * fConst0);
	fConst22 = ((fConst0 * (4.66264381601528e-15 - fConst21)) - 2.30823951287885e-13);
	fConst23 = (4.57031423550013e-19 * fConst0);
	fConst24 = (4.61647902575771e-13 + (fConst0 * (fConst23 - 4.6395614208865e-15)));
	fConst25 = (4.61647902575771e-21 * fConst0);
	fConst26 = (4.61647902575771e-15 + (fConst0 * (fConst25 - 4.6395614208865e-17)));
	fConst27 = (9.23295805151541e-20 * fConst0);
	fConst28 = (1.39967715142654e-08 + (fConst0 * ((fConst0 * (1.15873623546518e-15 - fConst27)) - 5.13067621086072e-12)));
	fConst29 = (9.18679326125784e-20 * fConst0);
	fConst30 = ((fConst0 * (5.15375860598951e-12 + (fConst0 * (fConst29 - 1.15642799595231e-15)))) - 1.39967715142654e-08);
	fConst31 = ((fConst0 * (4.74893268461376e-13 + (fConst0 * (fConst1 - 6.74157594007769e-17)))) - 2.90429276448603e-10);
	fConst32 = ((fConst0 * (2.58984473345007e-15 + (fConst0 * (fConst3 - 5.73274365418592e-18)))) - 5.0319621380759e-13);
	fConst33 = (4.61647902575771e-14 + (fConst0 * ((fConst0 * (6.47230359411231e-18 - fConst5)) - 1.33877891746973e-15)));
	fConst34 = (fConst0 * (1.0156253856667e-13 + (fConst0 * (fConst7 - 6.48153655216382e-16))));
	fConst35 = (4.61647902575771e-12 + (fConst0 * ((fConst0 * (6.42613880385473e-16 - fConst9)) - 1.32954595941822e-13)));
	fConst36 = (4.61647902575771e-11 + (fConst0 * ((fConst0 * (6.01804205797775e-16 - fConst11)) - 2.39133613534249e-13)));
	fConst37 = ((fConst0 * (2.67386465171886e-13 + (fConst0 * (fConst13 - 5.96818408449956e-16)))) - 5.0319621380759e-11);
	fConst38 = (3.10728327616692e-06 + (fConst0 * ((fConst0 * (5.11834981897011e-11 + (fConst0 * (fConst15 - 7.28293766644376e-15)))) - 2.95412127107681e-08)));
	fConst39 = ((fConst0 * (2.73960527750481e-08 + (fConst0 * ((fConst0 * (7.32221506288674e-15 - fConst17)) - 5.13010455324519e-11)))) - 2.79935430285308e-06);
	fConst40 = (2.0386371377746e-20 * fConst0);
	fConst41 = faustpower<2>(fConst0);
	fConst42 = ((fConst41 * (1.34831518801554e-16 - fConst40)) - 5.80858552897206e-10);
	fConst43 = (6.6477297970911e-22 * fConst0);
	fConst44 = ((fConst41 * (1.14654873083718e-17 - fConst43)) - 1.00639242761518e-12);
	fConst45 = (7.38636644121233e-22 * fConst0);
	fConst46 = (9.23295805151541e-14 + (fConst41 * (fConst45 - 1.29446071882246e-17)));
	fConst47 = (7.38636644121233e-20 * fConst0);
	fConst48 = (fConst41 * (1.29630731043276e-15 - fConst47));
	fConst49 = (7.31250277680021e-20 * fConst0);
	fConst50 = (9.23295805151541e-12 + (fConst41 * (fConst49 - 1.28522776077095e-15)));
	fConst51 = (5.90909315296986e-20 * fConst0);
	fConst52 = (9.23295805151541e-11 + (fConst41 * (fConst51 - 1.20360841159555e-15)));
	fConst53 = (5.84261585499895e-20 * fConst0);
	fConst54 = ((fConst41 * (1.19363681689991e-15 - fConst53)) - 1.00639242761518e-10);
	fConst55 = (2.21029629386838e-18 * fConst0);
	fConst56 = (1.24291331046677e-05 + (fConst0 * ((fConst41 * (1.45658753328875e-14 - fConst55)) - 5.90824254215363e-08)));
	fConst57 = (2.23068266524612e-18 * fConst0);
	fConst58 = ((fConst0 * (5.47921055500963e-08 + (fConst41 * (fConst57 - 1.46444301257735e-14)))) - 1.11974172114123e-05);
	fConst59 = (2.67755783493947e-15 - (1.10795496618185e-21 * fConst41));
	fConst60 = ((1.10795496618185e-19 * fConst41) - 2.03125077133339e-13);
	fConst61 = (2.65909191883644e-13 - (1.09687541652003e-19 * fConst41));
	fConst62 = (4.78267227068498e-13 - (8.8636397294548e-20 * fConst41));
	fConst63 = ((8.76392378249843e-20 * fConst41) - 5.34772930343773e-13);
	fConst64 = ((9.97159469563665e-22 * fConst41) - 5.17968946690015e-15);
	fConst65 = ((3.05795570666191e-20 * fConst41) - 9.49786536922751e-13);
	fConst66 = (1.86436996570015e-05 + (fConst41 * ((3.31544444080257e-18 * fConst41) - 1.02366996379402e-10)));
	fConst67 = ((fConst41 * (1.02602091064904e-10 - (3.34602399786919e-18 * fConst41))) - 1.67961258171185e-05);
	fConst68 = (5.80858552897206e-10 + (fConst41 * (0 - (1.34831518801554e-16 + fConst40))));
	fConst69 = (1.00639242761518e-12 + (fConst41 * (0 - (1.14654873083718e-17 + fConst43))));
	fConst70 = ((fConst41 * (1.29446071882246e-17 + fConst45)) - 9.23295805151541e-14);
	fConst71 = (fConst41 * (0 - (1.29630731043276e-15 + fConst47)));
	fConst72 = ((fConst41 * (1.28522776077095e-15 + fConst49)) - 9.23295805151541e-12);
	fConst73 = ((fConst41 * (1.20360841159555e-15 + fConst51)) - 9.23295805151541e-11);
	fConst74 = (1.00639242761518e-10 + (fConst41 * (0 - (1.19363681689991e-15 + fConst53))));
	fConst75 = (1.24291331046677e-05 + (fConst0 * (5.90824254215363e-08 + (fConst41 * (0 - (1.45658753328875e-14 + fConst55))))));
	fConst76 = ((fConst0 * ((fConst41 * (1.46444301257735e-14 + fConst57)) - 5.47921055500963e-08)) - 1.11974172114123e-05);
	fConst77 = (1.84659161030308e-21 * fConst0);
	fConst78 = ((fConst41 * (1.38956018675307e-17 - fConst77)) - 2.79935430285308e-10);
	fConst79 = (1.84659161030308e-18 * fConst0);
	fConst80 = (fConst79 - 9.32528763203057e-15);
	fConst81 = (1.82812569420005e-18 * fConst0);
	fConst82 = (9.27912284177299e-15 - fConst81);
	fConst83 = (9.27912284177299e-17 - fConst7);
	fConst84 = (3.69318322060617e-19 * fConst0);
	fConst85 = (2.79935430285308e-08 + (fConst41 * (fConst84 - 2.31747247093037e-15)));
	fConst86 = (3.67471730450314e-19 * fConst0);
	fConst87 = ((fConst41 * (2.31285599190461e-15 - fConst86)) - 2.79935430285308e-08);
	fConst88 = (4.61647902575771e-13 - (2.76988741545462e-18 * fConst41));
	fConst89 = ((2.74218854130008e-18 * fConst41) - 9.23295805151541e-13);
	fConst90 = ((2.76988741545462e-20 * fConst41) - 9.23295805151541e-15);
	fConst91 = (1.02613524217214e-11 - (5.53977483090925e-19 * fConst41));
	fConst92 = ((5.5120759567547e-19 * fConst41) - 1.0307517211979e-11);
	fConst93 = ((2.76988741545462e-21 * fConst41) - 4.70880860627286e-14);
	fConst94 = (2.79935430285308e-10 + (fConst41 * (0 - (1.38956018675307e-17 + fConst77))));
	fConst95 = (9.32528763203057e-15 + fConst79);
	fConst96 = (0 - (9.27912284177299e-15 + fConst81));
	fConst97 = (0 - (9.27912284177299e-17 + fConst7));
	fConst98 = ((fConst41 * (2.31747247093037e-15 + fConst84)) - 2.79935430285308e-08);
	fConst99 = (2.79935430285308e-08 + (fConst41 * (0 - (2.31285599190461e-15 + fConst86))));
	fConst100 = (1.39967715142654e-10 + (fConst0 * (2.35440430313643e-14 + (fConst0 * (6.94780093376535e-18 + fConst19)))));
	fConst101 = ((fConst0 * (0 - (4.66264381601528e-15 + fConst21))) - 2.30823951287885e-13);
	fConst102 = (4.61647902575771e-13 + (fConst0 * (4.6395614208865e-15 + fConst23)));
	fConst103 = (4.61647902575771e-15 + (fConst0 * (4.6395614208865e-17 + fConst25)));
	fConst104 = ((fConst0 * ((fConst0 * (0 - (1.15873623546518e-15 + fConst27))) - 5.13067621086072e-12)) - 1.39967715142654e-08);
	fConst105 = (1.39967715142654e-08 + (fConst0 * (5.15375860598951e-12 + (fConst0 * (1.15642799595231e-15 + fConst29)))));
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
		double fTemp0 = (3.10728327616692e-08 + ((fRec0[0] * ((fConst18 * fRec0[0]) + fConst16)) + (fConst0 * ((fRec1[0] * (((fRec0[0] * (fConst14 + (fConst12 * fRec0[0]))) + (fRec1[0] * ((fRec0[0] * (fConst10 + (fConst8 * fRec0[0]))) + fConst6))) + fConst4)) + fConst2))));
		fRec2[0] = ((double)input0[i] - (((((fRec2[1] * (1.24291331046677e-07 + ((fRec0[0] * ((fConst76 * fRec0[0]) + fConst75)) + (fConst0 * ((fRec1[0] * (((fRec0[0] * (fConst74 + (fConst73 * fRec0[0]))) + (fRec1[0] * ((fRec0[0] * (fConst72 + (fConst71 * fRec0[0]))) + fConst70))) + fConst69)) + fConst68))))) + (fRec2[2] * (1.86436996570015e-07 + ((fRec0[0] * ((fConst67 * fRec0[0]) + fConst66)) + (fConst41 * (fConst65 + (fRec1[0] * (fConst64 + ((fRec0[0] * (fConst63 + (fConst62 * fRec0[0]))) + (fRec1[0] * ((fRec0[0] * (fConst61 + (fConst60 * fRec0[0]))) + fConst59))))))))))) + (fRec2[3] * (1.24291331046677e-07 + ((fRec0[0] * ((fConst58 * fRec0[0]) + fConst56)) + (fConst0 * ((fRec1[0] * (((fRec0[0] * (fConst54 + (fConst52 * fRec0[0]))) + (fRec1[0] * ((fRec0[0] * (fConst50 + (fConst48 * fRec0[0]))) + fConst46))) + fConst44)) + fConst42)))))) + (fRec2[4] * (3.10728327616692e-08 + ((fRec0[0] * ((fConst39 * fRec0[0]) + fConst38)) + (fConst0 * ((fRec1[0] * (((fRec0[0] * (fConst37 + (fConst36 * fRec0[0]))) + (fRec1[0] * ((fRec0[0] * (fConst35 + (fConst34 * fRec0[0]))) + fConst33))) + fConst32)) + fConst31)))))) / fTemp0));
		fRec3[0] = ((0.993 * fRec3[1]) + fSlow2);
		output0[i] = (FAUSTFLOAT)(fConst0 * ((fRec3[0] * (((((fRec2[0] * (((fRec0[0] * (fConst105 + (fConst104 * fRec0[0]))) + (fConst0 * (fRec1[0] * (fConst103 + (fRec0[0] * (fConst102 + (fConst101 * fRec0[0]))))))) + fConst100)) + (fRec2[1] * (((fRec0[0] * (fConst99 + (fConst98 * fRec0[0]))) + (fConst41 * (fRec1[0] * (fConst97 + (fRec0[0] * (fConst96 + (fConst95 * fRec0[0]))))))) + fConst94))) + (fConst0 * (fRec2[2] * (fConst93 + ((fRec0[0] * (fConst92 + (fConst91 * fRec0[0]))) + (fRec1[0] * (fConst90 + (fRec0[0] * (fConst89 + (fConst88 * fRec0[0])))))))))) + (fRec2[3] * (((fRec0[0] * (fConst87 + (fConst85 * fRec0[0]))) + (fConst41 * (fRec1[0] * (fConst83 + (fRec0[0] * (fConst82 + (fConst80 * fRec0[0]))))))) + fConst78))) + (fRec2[4] * (((fRec0[0] * (fConst30 + (fConst28 * fRec0[0]))) + (fConst0 * (fRec1[0] * (fConst26 + (fRec0[0] * (fConst24 + (fConst22 * fRec0[0]))))))) + fConst20)))) / fTemp0));
		// post processing
		fRec3[1] = fRec3[0];
		for (int i=4; i>0; i--) fRec2[i] = fRec2[i-1];
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

} // end namespace mbr1
