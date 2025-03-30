#include "clean_test_header.h"

int main(void)
{
	int	tab[] = {906, 255, 521, 902, 404, 426, 473, 147, 717, 952, 251, 432, 200, 791, 318, 817, 646, 481, 693, 538, 630, 301, 919, 720, 594, 930, 460, 445, 306, 523, 559, 641, 812, 361, 425, 32, 354, 607, 908, 416, 668, 364, 297, 253, 845, 218, 905, 21, 313, 763, 225, 727, 555, 252, 287, 874, 511, 151, 317, 851, 769, 664, 730, 20, 517, 865, 963, 620, 120, 916, 281, 477, 295, 413, 921, 237, 888, 995, 117, 412, 702, 176, 703, 275, 323, 328, 572, 46, 125, 61, 628, 187, 635, 998, 537, 197, 217, 475, 781, 739, 542, 894, 420, 1000, 19, 977, 199, 283, 424, 600, 807, 278, 77, 965, 546, 734, 262, 195, 311, 663, 866, 705, 935, 123, 728, 706, 914, 506, 834, 528, 415, 407, 79, 136, 875, 321, 648, 465, 796, 98, 173, 653, 500, 940, 149, 922, 766, 722, 36, 589, 238, 293, 302, 624, 243, 886, 339, 928, 631, 576, 990};
	t_data	data;

	ft_memset(&data, 0, sizeof(t_data));
	data.size = 140;
	data.bfprt.size = data.size;
	data.bfprt.alloc.tab = calloc(data.size, sizeof(int));
	data.bfprt.fpivot.tab = calloc(data.size, sizeof(int));
	data.tab = calloc(data.size, sizeof(int));
	ft_memcpy(data.bfprt.alloc.tab, tab, data.size * sizeof(int));
	ft_memcpy(data.bfprt.fpivot.tab, tab, data.size * sizeof(int));
	ft_memcpy(data.tab, tab, data.size * sizeof(int));
	// partie du main pour tester le pivot finder
	bfprt_main(&data);
	printf("(main) pivot trouve : %d\nson index : %d\n", data.bfprt.pivot, data.bfprt.pivotindex);
	if (data.bfprt.alloc.tab)
		free(data.bfprt.alloc.tab);
	if (data.bfprt.fpivot.tab)
		free(data.bfprt.fpivot.tab);
	if (data.tab)
		free(data.tab);
	if (data.bfprt.fpivot.tot)
		free_tot(data.bfprt.fpivot.gn, &data);
	return (0);
}