#include <stdio.h>
#include "loess.h"

struct	loess_struct	madeup, madeup_new, madeup2;
struct  pred_struct     madeup_pred;
struct  ci_struct       madeup_ci;
struct  anova_struct    madeup_anova;
double	one_two[] = {-0.957581198938384, -2.80954937859791, -0.696510845605909,
	3.45100038854536, 0.509259838818042, 0.557854035598286, 
	0.0525817201002309, -2.05064423770094, -1.11567547099143, 
	-1.18366549451658, 0.511958575232253, 0.334364244817592, 
	-2.05706205756846, -0.121896645718402, 0.54423804521097, 
	0.600501641888935, 0.531074442421607, 0.495400347786053, 
	-1.60860176347294, 0.277370954937718, 0.290464363258084, 
	0.579894254111128, -0.290441177117614, 1.30622601704777, 
	-0.482897816720494, -0.716423394441349, 0.742412540254878,
	-0.91161346344296, 1.27943556865527, -0.189153217811851, 
	0.592292730243945, 0.952415888511291, 0.491436176457309, 
	-0.30568088056691, -0.363871357644093, -0.285424162901343, 
	-0.0372094292657342, -0.923529247741133, 1.13805430719146, 
	-1.33122338081553, 0.55123448290722, -0.852726057929887, 
	1.19687530878469, 0.498781686408254, 0.320179856418398, 
	0.21244678210441, 1.00935803951191, -0.900989007058962, 
	1.13216444413294, 0.0188670824356362, 0.424169515300288, 
	-0.19862121711326, 0.955170163539181, 0.948320512371124, 
	0.473848149342783, -0.699121305560135, -0.612853026250685, 
	0.580431200426044, 1.27799640925722, 0.806797458367235, 
	-1.03855925707748, 1.00866312622584, -0.578256568822387, 
	-0.323244575961333, -0.756301997657156, 1.38635211208482, 
	0.722419488760045, -1.2160777034384, -0.498279906600592, 
	0.726247405185,	-0.260119271608589, -0.741134528045221, 
	-0.184110574491516, 0.307761674659839, 0.464568227698959, 
	-0.25253136951752, -0.486503680414154, 0.426634057655542, 
	-1.30396915580526, 0.0671486396913438, 1.77117635735777, 
	0.907249468179712, 0.432349548721498, 1.41989705188111, 
	-0.413389471016361, 2.44202481656431, 0.0411377482323225, 
	0.509505377681864, -0.282743502058313, 0.179881630718384, 
	-1.18808328118875, 0.98265314676344, -1.04288590077335, 
	1.18136543233696, -0.398339818481707, -1.33556478800344, 
	-0.502789555455575, 0.484761653956289, -0.806445812279308, 
	1.41207651978306, -0.878873945799123, -0.935197083131863,
	-0.33925477332393439, 0.16449721487453731, 1.3700178698345999,
	-1.4946841727166, 1.3805047732704381, 
	0.88508389905048512, 0.83560940141892148, 0.89623509727336315,
	-1.289541425794579, 0.2332028995229195, 1.183197522953588, 
	-0.85793361589157902, -1.33423445483833, -0.9233512315474407, 
	0.76914556896670361, -0.37794794349382183, 0.059114341211622581, 
	-1.8706153553475069, -0.67786838062170507, 0.038184754648735768, 
	0.37530087746353391, 0.96471695952212921, 0.69505105492152874, 
	-0.34214020737803602, -1.1454631827640021, -0.99324551114161375, 
	-0.13057284978088679, 1.213711380869505, 0.29124075688915307, 
	1.106890512068581, 0.94957063346615733, 0.46367541051066768, 
	0.45572327290248621, 0.39878553409592049, -0.015849431703916221, 
	-1.3973725035064171, 0.7700624622976332, 0.083291190129894818, 
	0.53179773252409901, 0.049727349788233177, -0.73414037626738005, 
	-0.96348659055127073, 0.57356064323574374, -0.28194211032947131, 
	-0.59450289683584279, 0.77026173196827941, 1.0739830028467161, 
	-0.61570603602075391, -0.084794357704615464, -0.49163022652120109, 
	-1.526968705617602, -0.19688130817103111, 0.1656534453607213, 
	0.19835657518696179, 0.97492977599052544, -0.95484796495550817, 
	0.58847390467129868, -0.42688317000127768, 0.1771186872105201, 
	-0.91644209647809238, -1.8851386926119349, 0.086893856222760746, 
	0.45630642515021741, 0.17428542070878469, -0.0013077214871275221, 
	-0.00058541929918550742, 0.28402285608099398, -0.36567881757010029, 
	-0.54886653165173238, 0.8578476816688223, 0.69909448655308448, 
	-0.14002628501260239, 1.332454137144605, 1.6017946938719501, 
	0.01241549637061686, 0.24342918633361621, 1.0773689561938919, 
	1.8592463357601141, 0.18590984985424869, 0.033342258305766252, 
	0.6130082357970067, 1.068594886375418, -0.68330464261374424, 
	-0.12882583544682871, -1.6555248021907429, 0.013086014377651681, 
	0.062454455755349927, 0.77304176654886514, 0.12704646649909671, 
	0.40865153244567209, 1.195437623807228, -0.18555786800092541, 
	-1.299714084101439, 0.89967540292281434, -0.033647925669371137, 
	-1.5446015243088369, 0.65520298400478949, -0.71393501757996425};
double	response[] = {14.4535533874191, 6.62282520910778, 13.6714139876233,
	14.1975175236874, 12.8605301149348, 12.5228556826206, 14.2146384581959, 
	7.9242642010286, 12.5069380013745, 13.7342047122325, 14.7108554131065, 
	13.5962229304995, 5.89001909002711, 13.5586535685782, 14.0431671811957, 
	13.9313910018427, 13.2189198447833, 17.0905598230825, 15.1993220372035, 
	13.2616669404325, 15.7606359467964, 12.0838552528602, 14.344906985408, 
	12.6094936116173, 11.9329594317628, 13.4086741328164, 13.7007653532941, 
	13.0133656112894, 15.794998892751, 14.600198458049, 16.2757508936254, 
	11.5643493993645, 14.8090225170414, 12.9823612913134, 15.003502495484, 
	14.7373366435951, 15.7476765061616, 11.6745084114309, 14.047278212178, 
	14.6669170934119, 13.8062403198314, 13.6111487435938, 13.3471486192318, 
	14.2251519152709, 14.7188461068404, 14.2172164843947, 14.4180584862351, 
	14.7196335400403, 12.799715984732, 13.9330377247579, 15.2646032349699, 
	14.6603872891079, 9.73869078623634, 14.4434243169553, 14.4172837909381, 
	15.1845379738711, 13.3449384473427, 15.3729427547467, 13.8115544407009, 
	15.103777322749, 15.3838341258708, 14.368611819712, 12.525202176137, 
	14.3250330647389, 15.2596577477861, 13.0045474727206, 14.515987797507, 
	15.176981889542, 14.9241874861469, 13.872430121229, 15.3953655496863, 
	13.4280761187509, 15.2034304536162, 14.1866308929129, 13.3058326261246, 
	14.0746238485616, 14.1030921763152, 13.49966901054, 11.5846746059002, 
	14.2648911116312, 14.88561614061, 13.9672969505607, 16.604679813678, 
	10.3676055239145, 14.7434725924834, 16.3088265042892, 14.1086733681544, 
	13.5909878288487, 14.6745463058857, 15.2940472804827, 14.6867226502357, 
	13.6114224063955, 11.9702698734486, 13.8841573398, 15.0717757159234, 
	12.5898155750775, 13.8187450898422, 14.2453171289186, 14.4065299197652, 
	14.3479407847109};
double  newdata1[] = {-2.5, 0., 2.5, 0., 0., 0.};
double  newdata2[] = {-0.5, 0.5, 0., 0.};
double  coverage = .99;
int32_t	n = 100, p = 2, m = 3, se_fit = FALSE;
int     i;

main() {
        printf("\nloess(&madeup):\n");
	loess_setup(one_two, response, n, p, &madeup);
        madeup.model.span = 0.5;
        loess(&madeup);
        loess_summary(&madeup);

        printf("\nloess(&madeup_new):\n");
	loess_setup(one_two, response, n, p, &madeup_new);
	madeup_new.model.span = 0.8;
	madeup_new.model.drop_square[0] = TRUE;
	madeup_new.model.parametric[0] = TRUE;
	loess(&madeup_new);
	loess_summary(&madeup_new);

	printf("\nloess(&madeup_new) (family = symmetric):\n");
	madeup_new.model.family = "symmetric";
        loess(&madeup_new);
        loess_summary(&madeup_new);
	
	printf("\nloess(&madeup_new) (normalize = FALSE):\n");
	madeup_new.model.normalize = FALSE;
        loess(&madeup_new);
        loess_summary(&madeup_new);

	printf("\npredict(newdata1, m, &madeup, &madeup_pred, %d):\n", se_fit);
	predict(newdata1, m, &madeup, &madeup_pred, se_fit);
	printf("%g %g %g\n", madeup_pred.fit[0],
               madeup_pred.fit[1], madeup_pred.fit[2]);

	m = 2;
	se_fit = TRUE;
	printf("\npredict(newdata2, m, &madeup, &madeup_pred, %d):\n", se_fit);
	predict(newdata2, m, &madeup, &madeup_pred, se_fit);
	printf("%g %g\n", madeup_pred.fit[0], madeup_pred.fit[1]);
	printf("%g %g\n", madeup_pred.se_fit[0], madeup_pred.se_fit[1]);
	printf("%g\n", madeup_pred.residual_scale);
	printf("%g\n", madeup_pred.df);

	printf("\npointwise(&madeup_pred, m, coverage, &madeup_ci):\n");
	pointwise(&madeup_pred, m, coverage, &madeup_ci);
	for(i = 0; i < m; i++)
              printf("%g ", madeup_ci.upper[i]);
	printf("\n");
	for(i = 0; i < m; i++)
	      printf("%g ", madeup_ci.fit[i]);
	printf("\n");
	for(i = 0; i < m; i++)
	      printf("%g ", madeup_ci.lower[i]);
	printf("\n");

	loess_setup(one_two, response, n, p, &madeup2);
	madeup2.model.span = 0.75;
	loess(&madeup2);

	printf("\nanova(&madeup2, &madeup, &madeup_anova):\n");
	anova(&madeup2, &madeup, &madeup_anova);
	printf("%g %g %g %g\n", madeup_anova.dfn, madeup_anova.dfd,
	        madeup_anova.F_value, madeup_anova.Pr_F);
	
        loess_free_mem(&madeup);
	loess_free_mem(&madeup2);
	loess_free_mem(&madeup_new);
	pred_free_mem(&madeup_pred);
	pw_free_mem(&madeup_ci);
}
