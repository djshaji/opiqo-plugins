// generated from file './/mbr.dsp' by dsp2cc:
// Code generated with Faust 0.9.73 (http://faust.grame.fr)


namespace mbr {

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
	name = N_("MBR");
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
	fConst1 = (5.14362813305331e-21 * fConst0);
	fConst2 = (2.53393148251642e-10 + (fConst0 * (4.18387811921173e-13 + (fConst0 * (6.63229847822831e-17 + fConst1)))));
	fConst3 = (1.67727004338695e-22 * fConst0);
	fConst4 = (5.07840096469938e-13 + (fConst0 * (2.61374581761133e-15 + (fConst0 * (5.78564983299421e-18 + fConst3)))));
	fConst5 = (1.86363338154106e-22 * fConst0);
	fConst6 = ((fConst0 * ((fConst0 * (0 - (6.5320350023014e-18 + fConst5))) - 1.35113420161727e-15)) - 4.65908345385264e-14);
	fConst7 = (1.86363338154106e-20 * fConst0);
	fConst8 = (fConst0 * (1.02499835984758e-13 + (fConst0 * (6.5413531692091e-16 + fConst7))));
	fConst9 = (1.84499704772565e-20 * fConst0);
	fConst10 = ((fConst0 * ((fConst0 * (0 - (6.48544416776287e-16 + fConst9))) - 1.34181603470956e-13)) - 4.65908345385264e-12);
	fConst11 = (1.49090670523284e-20 * fConst0);
	fConst12 = ((fConst0 * ((fConst0 * (0 - (6.0735811904423e-16 + fConst11))) - 2.41340522909567e-13)) - 4.65908345385264e-11);
	fConst13 = (1.47413400479898e-20 * fConst0);
	fConst14 = (5.07840096469938e-11 + (fConst0 * (2.69854113647145e-13 + (fConst0 * (6.02326308914069e-16 + fConst13)))));
	fConst15 = (5.57673653092345e-19 * fConst0);
	fConst16 = (2.70332728583768e-06 + (fConst0 * (2.57728213628931e-08 + (fConst0 * (4.50642561961587e-11 + (fConst0 * (7.16478089063871e-15 + fConst15)))))));
	fConst17 = (5.62817281225399e-19 * fConst0);
	fConst18 = ((fConst0 * ((fConst0 * ((fConst0 * (0 - (7.20270582995307e-15 + fConst17))) - 4.51314401795632e-11)) - 2.3899403906099e-08)) - 2.43542998724115e-06);
	fConst19 = (4.65908345385264e-22 * fConst0);
	fConst20 = ((fConst0 * (2.37613256146485e-14 + (fConst0 * (fConst19 - 7.01192059804822e-18)))) - 1.21771499362058e-10);
	fConst21 = (4.65908345385264e-19 * fConst0);
	fConst22 = ((fConst0 * (4.70567428839117e-15 - fConst21)) - 2.32954172692632e-13);
	fConst23 = (4.61249261931411e-19 * fConst0);
	fConst24 = (4.65908345385264e-13 + (fConst0 * (fConst23 - 4.6823788711219e-15)));
	fConst25 = (4.65908345385264e-21 * fConst0);
	fConst26 = (4.65908345385264e-15 + (fConst0 * (fConst25 - 4.6823788711219e-17)));
	fConst27 = (9.31816690770528e-20 * fConst0);
	fConst28 = (1.21771499362058e-08 + (fConst0 * ((fConst0 * (1.16942994691701e-15 - fConst27)) - 4.78826713143674e-12)));
	fConst29 = (9.27157607316675e-20 * fConst0);
	fConst30 = ((fConst0 * (4.811562548706e-12 + (fConst0 * (fConst29 - 1.16710040519009e-15)))) - 1.21771499362058e-08);
	fConst31 = ((fConst0 * (4.18387811921173e-13 + (fConst0 * (fConst1 - 6.63229847822831e-17)))) - 2.53393148251642e-10);
	fConst32 = ((fConst0 * (2.61374581761133e-15 + (fConst0 * (fConst3 - 5.78564983299421e-18)))) - 5.07840096469938e-13);
	fConst33 = (4.65908345385264e-14 + (fConst0 * ((fConst0 * (6.5320350023014e-18 - fConst5)) - 1.35113420161727e-15)));
	fConst34 = (fConst0 * (1.02499835984758e-13 + (fConst0 * (fConst7 - 6.5413531692091e-16))));
	fConst35 = (4.65908345385264e-12 + (fConst0 * ((fConst0 * (6.48544416776287e-16 - fConst9)) - 1.34181603470956e-13)));
	fConst36 = (4.65908345385264e-11 + (fConst0 * ((fConst0 * (6.0735811904423e-16 - fConst11)) - 2.41340522909567e-13)));
	fConst37 = ((fConst0 * (2.69854113647145e-13 + (fConst0 * (fConst13 - 6.02326308914069e-16)))) - 5.07840096469938e-11);
	fConst38 = (2.70332728583768e-06 + (fConst0 * ((fConst0 * (4.50642561961587e-11 + (fConst0 * (fConst15 - 7.16478089063871e-15)))) - 2.57728213628931e-08)));
	fConst39 = ((fConst0 * (2.3899403906099e-08 + (fConst0 * ((fConst0 * (7.20270582995307e-15 - fConst17)) - 4.51314401795632e-11)))) - 2.43542998724115e-06);
	fConst40 = (2.05745125322133e-20 * fConst0);
	fConst41 = faustpower<2>(fConst0);
	fConst42 = ((fConst41 * (1.32645969564566e-16 - fConst40)) - 5.06786296503284e-10);
	fConst43 = (6.7090801735478e-22 * fConst0);
	fConst44 = ((fConst41 * (1.15712996659884e-17 - fConst43)) - 1.01568019293988e-12);
	fConst45 = (7.45453352616422e-22 * fConst0);
	fConst46 = (9.31816690770528e-14 + (fConst41 * (fConst45 - 1.30640700046028e-17)));
	fConst47 = (7.45453352616422e-20 * fConst0);
	fConst48 = (fConst41 * (1.30827063384182e-15 - fConst47));
	fConst49 = (7.37998819090258e-20 * fConst0);
	fConst50 = (9.31816690770528e-12 + (fConst41 * (fConst49 - 1.29708883355257e-15)));
	fConst51 = (5.96362682093138e-20 * fConst0);
	fConst52 = (9.31816690770528e-11 + (fConst41 * (fConst51 - 1.21471623808846e-15)));
	fConst53 = (5.8965360191959e-20 * fConst0);
	fConst54 = ((fConst41 * (1.20465261782814e-15 - fConst53)) - 1.01568019293988e-10);
	fConst55 = (2.23069461236938e-18 * fConst0);
	fConst56 = (1.08133091433507e-05 + (fConst0 * ((fConst41 * (1.43295617812774e-14 - fConst55)) - 5.15456427257863e-08)));
	fConst57 = (2.2512691249016e-18 * fConst0);
	fConst58 = ((fConst0 * (4.7798807812198e-08 + (fConst41 * (fConst57 - 1.44054116599061e-14)))) - 9.74171994896461e-06);
	fConst59 = (2.70226840323453e-15 - (1.11818002892463e-21 * fConst41));
	fConst60 = ((1.11818002892463e-19 * fConst41) - 2.04999671969516e-13);
	fConst61 = (2.68363206941912e-13 - (1.10699822863539e-19 * fConst41));
	fConst62 = (4.82681045819133e-13 - (8.94544023139707e-20 * fConst41));
	fConst63 = ((8.84480402879385e-20 * fConst41) - 5.3970822729429e-13);
	fConst64 = ((1.00636202603217e-21 * fConst41) - 5.22749163522266e-15);
	fConst65 = ((3.08617687983199e-20 * fConst41) - 8.36775623842347e-13);
	fConst66 = (1.62199637150261e-05 + (fConst41 * ((3.34604191855407e-18 * fConst41) - 9.01285123923174e-11)));
	fConst67 = ((fConst41 * (9.02628803591265e-11 - (3.37690368735239e-18 * fConst41))) - 1.46125799234469e-05);
	fConst68 = (5.06786296503284e-10 + (fConst41 * (0 - (1.32645969564566e-16 + fConst40))));
	fConst69 = (1.01568019293988e-12 + (fConst41 * (0 - (1.15712996659884e-17 + fConst43))));
	fConst70 = ((fConst41 * (1.30640700046028e-17 + fConst45)) - 9.31816690770528e-14);
	fConst71 = (fConst41 * (0 - (1.30827063384182e-15 + fConst47)));
	fConst72 = ((fConst41 * (1.29708883355257e-15 + fConst49)) - 9.31816690770528e-12);
	fConst73 = ((fConst41 * (1.21471623808846e-15 + fConst51)) - 9.31816690770528e-11);
	fConst74 = (1.01568019293988e-10 + (fConst41 * (0 - (1.20465261782814e-15 + fConst53))));
	fConst75 = (1.08133091433507e-05 + (fConst0 * (5.15456427257863e-08 + (fConst41 * (0 - (1.43295617812774e-14 + fConst55))))));
	fConst76 = ((fConst0 * ((fConst41 * (1.44054116599061e-14 + fConst57)) - 4.7798807812198e-08)) - 9.74171994896461e-06);
	fConst77 = (1.86363338154106e-21 * fConst0);
	fConst78 = ((fConst41 * (1.40238411960964e-17 - fConst77)) - 2.43542998724115e-10);
	fConst79 = (1.86363338154106e-18 * fConst0);
	fConst80 = (fConst79 - 9.41134857678233e-15);
	fConst81 = (1.84499704772565e-18 * fConst0);
	fConst82 = (9.36475774224381e-15 - fConst81);
	fConst83 = (9.3647577422438e-17 - fConst7);
	fConst84 = (3.72726676308211e-19 * fConst0);
	fConst85 = (2.43542998724115e-08 + (fConst41 * (fConst84 - 2.33885989383402e-15)));
	fConst86 = (3.7086304292667e-19 * fConst0);
	fConst87 = ((fConst41 * (2.33420081038017e-15 - fConst86)) - 2.43542998724115e-08);
	fConst88 = (4.65908345385264e-13 - (2.79545007231158e-18 * fConst41));
	fConst89 = ((2.76749557158847e-18 * fConst41) - 9.31816690770528e-13);
	fConst90 = ((2.79545007231158e-20 * fConst41) - 9.31816690770528e-15);
	fConst91 = (9.57653426287347e-12 - (5.59090014462317e-19 * fConst41));
	fConst92 = ((5.56294564390005e-19 * fConst41) - 9.623125097412e-12);
	fConst93 = ((2.79545007231158e-21 * fConst41) - 4.75226512292969e-14);
	fConst94 = (2.43542998724115e-10 + (fConst41 * (0 - (1.40238411960964e-17 + fConst77))));
	fConst95 = (9.41134857678233e-15 + fConst79);
	fConst96 = (0 - (9.36475774224381e-15 + fConst81));
	fConst97 = (0 - (9.3647577422438e-17 + fConst7));
	fConst98 = ((fConst41 * (2.33885989383402e-15 + fConst84)) - 2.43542998724115e-08);
	fConst99 = (2.43542998724115e-08 + (fConst41 * (0 - (2.33420081038017e-15 + fConst86))));
	fConst100 = (1.21771499362058e-10 + (fConst0 * (2.37613256146485e-14 + (fConst0 * (7.01192059804822e-18 + fConst19)))));
	fConst101 = ((fConst0 * (0 - (4.70567428839117e-15 + fConst21))) - 2.32954172692632e-13);
	fConst102 = (4.65908345385264e-13 + (fConst0 * (4.6823788711219e-15 + fConst23)));
	fConst103 = (4.65908345385264e-15 + (fConst0 * (4.6823788711219e-17 + fConst25)));
	fConst104 = ((fConst0 * ((fConst0 * (0 - (1.16942994691701e-15 + fConst27))) - 4.78826713143674e-12)) - 1.21771499362058e-08);
	fConst105 = (1.21771499362058e-08 + (fConst0 * (4.811562548706e-12 + (fConst0 * (1.16710040519009e-15 + fConst29)))));
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
		double fTemp0 = (2.70332728583768e-08 + ((fRec0[0] * ((fConst18 * fRec0[0]) + fConst16)) + (fConst0 * ((fRec1[0] * (((fRec0[0] * (fConst14 + (fConst12 * fRec0[0]))) + (fRec1[0] * ((fRec0[0] * (fConst10 + (fConst8 * fRec0[0]))) + fConst6))) + fConst4)) + fConst2))));
		fRec2[0] = ((double)input0[i] - (((((fRec2[1] * (1.08133091433507e-07 + ((fRec0[0] * ((fConst76 * fRec0[0]) + fConst75)) + (fConst0 * ((fRec1[0] * (((fRec0[0] * (fConst74 + (fConst73 * fRec0[0]))) + (fRec1[0] * ((fRec0[0] * (fConst72 + (fConst71 * fRec0[0]))) + fConst70))) + fConst69)) + fConst68))))) + (fRec2[2] * (1.62199637150261e-07 + ((fRec0[0] * ((fConst67 * fRec0[0]) + fConst66)) + (fConst41 * (fConst65 + (fRec1[0] * (fConst64 + ((fRec0[0] * (fConst63 + (fConst62 * fRec0[0]))) + (fRec1[0] * ((fRec0[0] * (fConst61 + (fConst60 * fRec0[0]))) + fConst59))))))))))) + (fRec2[3] * (1.08133091433507e-07 + ((fRec0[0] * ((fConst58 * fRec0[0]) + fConst56)) + (fConst0 * ((fRec1[0] * (((fRec0[0] * (fConst54 + (fConst52 * fRec0[0]))) + (fRec1[0] * ((fRec0[0] * (fConst50 + (fConst48 * fRec0[0]))) + fConst46))) + fConst44)) + fConst42)))))) + (fRec2[4] * (2.70332728583768e-08 + ((fRec0[0] * ((fConst39 * fRec0[0]) + fConst38)) + (fConst0 * ((fRec1[0] * (((fRec0[0] * (fConst37 + (fConst36 * fRec0[0]))) + (fRec1[0] * ((fRec0[0] * (fConst35 + (fConst34 * fRec0[0]))) + fConst33))) + fConst32)) + fConst31)))))) / fTemp0));
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

} // end namespace mbr
