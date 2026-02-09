// generated from file './/mbr2.dsp' by dsp2cc:
// Code generated with Faust 0.9.73 (http://faust.grame.fr)


namespace mbr2 {

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
	name = N_("MBR2");
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
	fConst1 = (4.88635190300831e-21 * fConst0);
	fConst2 = (4.55975416123025e-10 + (fConst0 * (7.27464491647143e-13 + (fConst0 * (7.23003039909614e-17 + fConst1)))));
	fConst3 = (1.59337562054619e-22 * fConst0);
	fConst4 = (4.82438729554263e-13 + (fConst0 * (2.48301034201781e-15 + (fConst0 * (5.49626068220627e-18 + fConst3)))));
	fConst5 = (1.77041735616243e-22 * fConst0);
	fConst6 = ((fConst0 * ((fConst0 * (0 - (6.20531283334932e-18 + fConst5))) - 1.28355258321776e-15)) - 4.42604339040608e-14);
	fConst7 = (1.77041735616243e-20 * fConst0);
	fConst8 = (fConst0 * (9.73729545889338e-14 + (fConst0 * (6.21416492013014e-16 + fConst7))));
	fConst9 = (1.75271318260081e-20 * fConst0);
	fConst10 = ((fConst0 * ((fConst0 * (0 - (6.16105239944526e-16 + fConst9))) - 1.27470049643695e-13)) - 4.42604339040608e-12);
	fConst11 = (1.41633388492995e-20 * fConst0);
	fConst12 = ((fConst0 * ((fConst0 * (0 - (5.76979016373337e-16 + fConst11))) - 2.29269047623035e-13)) - 4.42604339040608e-11);
	fConst13 = (1.40040012872448e-20 * fConst0);
	fConst14 = (4.82438729554263e-11 + (fConst0 * (2.5635643317232e-13 + (fConst0 * (5.72198889511698e-16 + fConst13)))));
	fConst15 = (5.29779689658046e-19 * fConst0);
	fConst16 = (4.91290816335075e-06 + (fConst0 * (4.63853773357948e-08 + (fConst0 * (7.85356253984977e-11 + (fConst0 * (7.81108137538865e-15 + fConst15)))))));
	fConst17 = (5.34666041561055e-19 * fConst0);
	fConst18 = ((fConst0 * ((fConst0 * ((fConst0 * (0 - (7.85640405970641e-15 + fConst17))) - 7.88782896777829e-11)) - 4.30255677981375e-08)) - 4.42604339040608e-06);
	fConst19 = (4.42604339040608e-22 * fConst0);
	fConst20 = ((fConst0 * (2.2572821291071e-14 + (fConst0 * (fConst19 - 6.66119530256115e-18)))) - 2.21302169520304e-10);
	fConst21 = (4.42604339040608e-19 * fConst0);
	fConst22 = ((fConst0 * (4.47030382431014e-15 - fConst21)) - 2.21302169520304e-13);
	fConst23 = (4.38178295650202e-19 * fConst0);
	fConst24 = (4.42604339040608e-13 + (fConst0 * (fConst23 - 4.44817360735811e-15)));
	fConst25 = (4.42604339040608e-21 * fConst0);
	fConst26 = (4.42604339040608e-15 + (fConst0 * (fConst25 - 4.44817360735811e-17)));
	fConst27 = (8.85208678081216e-20 * fConst0);
	fConst28 = (2.21302169520304e-08 + (fConst0 * ((fConst0 * (1.11093689099193e-15 - fConst27)) - 6.66119530256115e-12)));
	fConst29 = (8.8078263469081e-20 * fConst0);
	fConst30 = ((fConst0 * (6.68332551951318e-12 + (fConst0 * (fConst29 - 1.10872386929672e-15)))) - 2.21302169520304e-08);
	fConst31 = ((fConst0 * (7.27464491647143e-13 + (fConst0 * (fConst1 - 7.23003039909614e-17)))) - 4.55975416123025e-10);
	fConst32 = ((fConst0 * (2.48301034201781e-15 + (fConst0 * (fConst3 - 5.49626068220627e-18)))) - 4.82438729554263e-13);
	fConst33 = (4.42604339040608e-14 + (fConst0 * ((fConst0 * (6.20531283334932e-18 - fConst5)) - 1.28355258321776e-15)));
	fConst34 = (fConst0 * (9.73729545889338e-14 + (fConst0 * (fConst7 - 6.21416492013014e-16))));
	fConst35 = (4.42604339040608e-12 + (fConst0 * ((fConst0 * (6.16105239944526e-16 - fConst9)) - 1.27470049643695e-13)));
	fConst36 = (4.42604339040608e-11 + (fConst0 * ((fConst0 * (5.76979016373337e-16 - fConst11)) - 2.29269047623035e-13)));
	fConst37 = ((fConst0 * (2.5635643317232e-13 + (fConst0 * (fConst13 - 5.72198889511698e-16)))) - 4.82438729554263e-11);
	fConst38 = (4.91290816335075e-06 + (fConst0 * ((fConst0 * (7.85356253984977e-11 + (fConst0 * (fConst15 - 7.81108137538865e-15)))) - 4.63853773357948e-08)));
	fConst39 = ((fConst0 * (4.30255677981375e-08 + (fConst0 * ((fConst0 * (7.85640405970641e-15 - fConst17)) - 7.88782896777829e-11)))) - 4.42604339040608e-06);
	fConst40 = (1.95454076120333e-20 * fConst0);
	fConst41 = faustpower<2>(fConst0);
	fConst42 = ((fConst41 * (1.44600607981923e-16 - fConst40)) - 9.1195083224605e-10);
	fConst43 = (6.37350248218476e-22 * fConst0);
	fConst44 = ((fConst41 * (1.09925213644125e-17 - fConst43)) - 9.64877459108526e-13);
	fConst45 = (7.08166942464973e-22 * fConst0);
	fConst46 = (8.85208678081216e-14 + (fConst41 * (fConst45 - 1.24106256666986e-17)));
	fConst47 = (7.08166942464973e-20 * fConst0);
	fConst48 = (fConst41 * (1.24283298402603e-15 - fConst47));
	fConst49 = (7.01085273040323e-20 * fConst0);
	fConst50 = (8.85208678081216e-12 + (fConst41 * (fConst49 - 1.23221047988905e-15)));
	fConst51 = (5.66533553971978e-20 * fConst0);
	fConst52 = (8.85208678081216e-11 + (fConst41 * (fConst51 - 1.15395803274667e-15)));
	fConst53 = (5.60160051489793e-20 * fConst0);
	fConst54 = ((fConst41 * (1.1443977790234e-15 - fConst53)) - 9.64877459108525e-11);
	fConst55 = (2.11911875863218e-18 * fConst0);
	fConst56 = (1.9651632653403e-05 + (fConst0 * ((fConst41 * (1.56221627507773e-14 - fConst55)) - 9.27707546715895e-08)));
	fConst57 = (2.13866416624422e-18 * fConst0);
	fConst58 = ((fConst0 * (8.6051135596275e-08 + (fConst41 * (fConst57 - 1.57128081194128e-14)))) - 1.77041735616243e-05);
	fConst59 = (2.56710516643553e-15 - (1.06225041369746e-21 * fConst41));
	fConst60 = ((1.06225041369746e-19 * fConst41) - 1.94745909177868e-13);
	fConst61 = (2.5494009928739e-13 - (1.05162790956048e-19 * fConst41));
	fConst62 = (4.5853809524607e-13 - (8.49800330957967e-20 * fConst41));
	fConst63 = ((8.4024007723469e-20 * fConst41) - 5.1271286634464e-13);
	fConst64 = ((9.56025372327713e-22 * fConst41) - 4.96602068403562e-15);
	fConst65 = ((2.93181114180499e-20 * fConst41) - 1.45492898329429e-12);
	fConst66 = (2.94774489801045e-05 + (fConst41 * ((3.17867813794828e-18 * fConst41) - 1.57071250796995e-10)));
	fConst67 = ((fConst41 * (1.57756579355566e-10 - (3.20799624936633e-18 * fConst41))) - 2.65562603424365e-05);
	fConst68 = (9.1195083224605e-10 + (fConst41 * (0 - (1.44600607981923e-16 + fConst40))));
	fConst69 = (9.64877459108526e-13 + (fConst41 * (0 - (1.09925213644125e-17 + fConst43))));
	fConst70 = ((fConst41 * (1.24106256666986e-17 + fConst45)) - 8.85208678081216e-14);
	fConst71 = (fConst41 * (0 - (1.24283298402603e-15 + fConst47)));
	fConst72 = ((fConst41 * (1.23221047988905e-15 + fConst49)) - 8.85208678081216e-12);
	fConst73 = ((fConst41 * (1.15395803274667e-15 + fConst51)) - 8.85208678081216e-11);
	fConst74 = (9.64877459108525e-11 + (fConst41 * (0 - (1.1443977790234e-15 + fConst53))));
	fConst75 = (1.9651632653403e-05 + (fConst0 * (9.27707546715895e-08 + (fConst41 * (0 - (1.56221627507773e-14 + fConst55))))));
	fConst76 = ((fConst0 * ((fConst41 * (1.57128081194128e-14 + fConst57)) - 8.6051135596275e-08)) - 1.77041735616243e-05);
	fConst77 = (1.77041735616243e-21 * fConst0);
	fConst78 = ((fConst41 * (1.33223906051223e-17 - fConst77)) - 4.42604339040608e-10);
	fConst79 = (1.77041735616243e-18 * fConst0);
	fConst80 = (fConst79 - 8.94060764862028e-15);
	fConst81 = (1.75271318260081e-18 * fConst0);
	fConst82 = (8.89634721471622e-15 - fConst81);
	fConst83 = (8.89634721471622e-17 - fConst7);
	fConst84 = (3.54083471232486e-19 * fConst0);
	fConst85 = (4.42604339040608e-08 + (fConst41 * (fConst84 - 2.22187378198385e-15)));
	fConst86 = (3.52313053876324e-19 * fConst0);
	fConst87 = ((fConst41 * (2.21744773859345e-15 - fConst86)) - 4.42604339040608e-08);
	fConst88 = (4.42604339040608e-13 - (2.65562603424365e-18 * fConst41));
	fConst89 = ((2.62906977390121e-18 * fConst41) - 8.85208678081216e-13);
	fConst90 = ((2.65562603424365e-20 * fConst41) - 8.85208678081216e-15);
	fConst91 = (1.33223906051223e-11 - (5.3112520684873e-19 * fConst41));
	fConst92 = ((5.28469580814486e-19 * fConst41) - 1.33666510390264e-11);
	fConst93 = ((2.65562603424365e-21 * fConst41) - 4.5145642582142e-14);
	fConst94 = (4.42604339040608e-10 + (fConst41 * (0 - (1.33223906051223e-17 + fConst77))));
	fConst95 = (8.94060764862028e-15 + fConst79);
	fConst96 = (0 - (8.89634721471622e-15 + fConst81));
	fConst97 = (0 - (8.89634721471622e-17 + fConst7));
	fConst98 = ((fConst41 * (2.22187378198385e-15 + fConst84)) - 4.42604339040608e-08);
	fConst99 = (4.42604339040608e-08 + (fConst41 * (0 - (2.21744773859345e-15 + fConst86))));
	fConst100 = (2.21302169520304e-10 + (fConst0 * (2.2572821291071e-14 + (fConst0 * (6.66119530256115e-18 + fConst19)))));
	fConst101 = ((fConst0 * (0 - (4.47030382431014e-15 + fConst21))) - 2.21302169520304e-13);
	fConst102 = (4.42604339040608e-13 + (fConst0 * (4.44817360735811e-15 + fConst23)));
	fConst103 = (4.42604339040608e-15 + (fConst0 * (4.44817360735811e-17 + fConst25)));
	fConst104 = ((fConst0 * ((fConst0 * (0 - (1.11093689099193e-15 + fConst27))) - 6.66119530256115e-12)) - 2.21302169520304e-08);
	fConst105 = (2.21302169520304e-08 + (fConst0 * (6.68332551951318e-12 + (fConst0 * (1.10872386929672e-15 + fConst29)))));
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
		double fTemp0 = (4.91290816335075e-08 + ((fRec0[0] * ((fConst18 * fRec0[0]) + fConst16)) + (fConst0 * ((fRec1[0] * (((fRec0[0] * (fConst14 + (fConst12 * fRec0[0]))) + (fRec1[0] * ((fRec0[0] * (fConst10 + (fConst8 * fRec0[0]))) + fConst6))) + fConst4)) + fConst2))));
		fRec2[0] = ((double)input0[i] - (((((fRec2[1] * (1.9651632653403e-07 + ((fRec0[0] * ((fConst76 * fRec0[0]) + fConst75)) + (fConst0 * ((fRec1[0] * (((fRec0[0] * (fConst74 + (fConst73 * fRec0[0]))) + (fRec1[0] * ((fRec0[0] * (fConst72 + (fConst71 * fRec0[0]))) + fConst70))) + fConst69)) + fConst68))))) + (fRec2[2] * (2.94774489801045e-07 + ((fRec0[0] * ((fConst67 * fRec0[0]) + fConst66)) + (fConst41 * (fConst65 + (fRec1[0] * (fConst64 + ((fRec0[0] * (fConst63 + (fConst62 * fRec0[0]))) + (fRec1[0] * ((fRec0[0] * (fConst61 + (fConst60 * fRec0[0]))) + fConst59))))))))))) + (fRec2[3] * (1.9651632653403e-07 + ((fRec0[0] * ((fConst58 * fRec0[0]) + fConst56)) + (fConst0 * ((fRec1[0] * (((fRec0[0] * (fConst54 + (fConst52 * fRec0[0]))) + (fRec1[0] * ((fRec0[0] * (fConst50 + (fConst48 * fRec0[0]))) + fConst46))) + fConst44)) + fConst42)))))) + (fRec2[4] * (4.91290816335075e-08 + ((fRec0[0] * ((fConst39 * fRec0[0]) + fConst38)) + (fConst0 * ((fRec1[0] * (((fRec0[0] * (fConst37 + (fConst36 * fRec0[0]))) + (fRec1[0] * ((fRec0[0] * (fConst35 + (fConst34 * fRec0[0]))) + fConst33))) + fConst32)) + fConst31)))))) / fTemp0));
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

} // end namespace mbr2
