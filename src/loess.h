/* for the meaning of these fields, see struct.m */
/* int32_t-s are used here so that the codes can be called from S */

#include <stdint.h>

#define TRUE  1
#define FALSE 0

extern struct loess_struct {
	struct {
		int32_t    n;
	        int32_t    p;
	        double  *y;
	        double  *x;
		double	*weights;
	} in;
	struct {
	        double  span;
	        int32_t    degree;
	        int32_t    normalize;
	        int32_t    parametric[8];
	        int32_t    drop_square[8];
	        char    *family;
	} model;
	struct {
	        char    *surface;
	        char    *statistics;
	        double  cell;
	        char    *trace_hat;
	        int32_t    iterations;
	} control;
	struct {
		int32_t	*parameter;
		int32_t	*a;
		double	*xi;
		double	*vert;
		double	*vval;
	} kd_tree;
	struct {
		double	*fitted_values;
	        double  *fitted_residuals;
		double  enp;
		double	s;
		double  one_delta;
		double	two_delta;
		double	*pseudovalues;
		double	trace_hat;
		double	*diagonal;
		double	*robust;
		double  *divisor;
	} out;
};

extern struct pred_struct {
	double	*fit;
	double	*se_fit;
	double  residual_scale;
	double  df;
};

extern struct anova_struct {
	double	dfn;
	double	dfd;
	double  F_value;
	double  Pr_F;
};

extern struct ci_struct {
	double	*fit;
	double	*upper;
	double  *lower;
};

