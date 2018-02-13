/*
 * sine.c
 *
 * Created: 3/26/2013 1:06:37 PM
 *  Author: mike
 */ 

#include <Arduino.h>

const int16_t _sine[1024] = 
{
  0,201,402,603,804,1005,1206,1407,
  1608,1809,2009,2210,2410,2611,2811,3012,
  3212,3412,3612,3811,4011,4210,4410,4609,
  4808,5007,5205,5404,5602,5800,5998,6195,
  6393,6590,6786,6983,7179,7375,7571,7767,
  7962,8157,8351,8545,8739,8933,9126,9319,
  9512,9704,9896,10087,10278,10469,10659,10849,
  11039,11228,11417,11605,11793,11980,12167,12353,
  12539,12725,12910,13094,13279,13462,13645,13828,
  14010,14191,14372,14553,14732,14912,15090,15269,
  15446,15623,15800,15976,16151,16325,16499,16673,
  16846,17018,17189,17360,17530,17700,17869,18037,
  18204,18371,18537,18703,18868,19032,19195,19357,
  19519,19680,19841,20000,20159,20317,20475,20631,
  20787,20942,21096,21250,21403,21554,21705,21856,
  22005,22154,22301,22448,22594,22739,22884,23027,
  23170,23311,23452,23592,23731,23870,24007,24143,
  24279,24413,24547,24680,24811,24942,25072,25201,
  25329,25456,25582,25708,25832,25955,26077,26198,
  26319,26438,26556,26674,26790,26905,27019,27133,
  27245,27356,27466,27575,27683,27790,27896,28001,
  28105,28208,28310,28411,28510,28609,28706,28803,
  28898,28992,29085,29177,29268,29358,29447,29534,
  29621,29706,29791,29874,29956,30037,30117,30195,
  30273,30349,30424,30498,30571,30643,30714,30783,
  30852,30919,30985,31050,31113,31176,31237,31297,
  31356,31414,31470,31526,31580,31633,31685,31736,
  31785,31833,31880,31926,31971,32014,32057,32098,
  32137,32176,32213,32250,32285,32318,32351,32382,
  32412,32441,32469,32495,32521,32545,32567,32589,
  32609,32628,32646,32663,32678,32692,32705,32717,
  32728,32737,32745,32752,32757,32761,32765,32766,
  32767,32766,32765,32761,32757,32752,32745,32737,
  32728,32717,32705,32692,32678,32663,32646,32628,
  32609,32589,32567,32545,32521,32495,32469,32441,
  32412,32382,32351,32318,32285,32250,32213,32176,
  32137,32098,32057,32014,31971,31926,31880,31833,
  31785,31736,31685,31633,31580,31526,31470,31414,
  31356,31297,31237,31176,31113,31050,30985,30919,
  30852,30783,30714,30643,30571,30498,30424,30349,
  30273,30195,30117,30037,29956,29874,29791,29706,
  29621,29534,29447,29358,29268,29177,29085,28992,
  28898,28803,28706,28609,28510,28411,28310,28208,
  28105,28001,27896,27790,27683,27575,27466,27356,
  27245,27133,27019,26905,26790,26674,26556,26438,
  26319,26198,26077,25955,25832,25708,25582,25456,
  25329,25201,25072,24942,24811,24680,24547,24413,
  24279,24143,24007,23870,23731,23592,23452,23311,
  23170,23027,22884,22739,22594,22448,22301,22154,
  22005,21856,21705,21554,21403,21250,21096,20942,
  20787,20631,20475,20317,20159,20000,19841,19680,
  19519,19357,19195,19032,18868,18703,18537,18371,
  18204,18037,17869,17700,17530,17360,17189,17018,
  16846,16673,16499,16325,16151,15976,15800,15623,
  15446,15269,15090,14912,14732,14553,14372,14191,
  14010,13828,13645,13462,13279,13094,12910,12725,
  12539,12353,12167,11980,11793,11605,11417,11228,
  11039,10849,10659,10469,10278,10087,9896,9704,
  9512,9319,9126,8933,8739,8545,8351,8157,
  7962,7767,7571,7375,7179,6983,6786,6590,
  6393,6195,5998,5800,5602,5404,5205,5007,
  4808,4609,4410,4210,4011,3811,3612,3412,
  3212,3012,2811,2611,2410,2210,2009,1809,
  1608,1407,1206,1005,804,603,402,201,  
  0,-201,-402,-603,-804,-1005,-1206,-1407,-
  1608,-1809,-2009,-2210,-2410,-2611,-2811,-3012,-
  3212,-3412,-3612,-3811,-4011,-4210,-4410,-4609,-
  4808,-5007,-5205,-5404,-5602,-5800,-5998,-6195,-
  6393,-6590,-6786,-6983,-7179,-7375,-7571,-7767,-
  7962,-8157,-8351,-8545,-8739,-8933,-9126,-9319,-
  9512,-9704,-9896,-10087,-10278,-10469,-10659,-10849,-
  11039,-11228,-11417,-11605,-11793,-11980,-12167,-12353,-
  12539,-12725,-12910,-13094,-13279,-13462,-13645,-13828,-
  14010,-14191,-14372,-14553,-14732,-14912,-15090,-15269,-
  15446,-15623,-15800,-15976,-16151,-16325,-16499,-16673,-
  16846,-17018,-17189,-17360,-17530,-17700,-17869,-18037,-
  18204,-18371,-18537,-18703,-18868,-19032,-19195,-19357,-
  19519,-19680,-19841,-20000,-20159,-20317,-20475,-20631,-
  20787,-20942,-21096,-21250,-21403,-21554,-21705,-21856,-
  22005,-22154,-22301,-22448,-22594,-22739,-22884,-23027,-
  23170,-23311,-23452,-23592,-23731,-23870,-24007,-24143,-
  24279,-24413,-24547,-24680,-24811,-24942,-25072,-25201,-
  25329,-25456,-25582,-25708,-25832,-25955,-26077,-26198,-
  26319,-26438,-26556,-26674,-26790,-26905,-27019,-27133,-
  27245,-27356,-27466,-27575,-27683,-27790,-27896,-28001,-
  28105,-28208,-28310,-28411,-28510,-28609,-28706,-28803,-
  28898,-28992,-29085,-29177,-29268,-29358,-29447,-29534,-
  29621,-29706,-29791,-29874,-29956,-30037,-30117,-30195,-
  30273,-30349,-30424,-30498,-30571,-30643,-30714,-30783,-
  30852,-30919,-30985,-31050,-31113,-31176,-31237,-31297,-
  31356,-31414,-31470,-31526,-31580,-31633,-31685,-31736,-
  31785,-31833,-31880,-31926,-31971,-32014,-32057,-32098,-
  32137,-32176,-32213,-32250,-32285,-32318,-32351,-32382,-
  32412,-32441,-32469,-32495,-32521,-32545,-32567,-32589,-
  32609,-32628,-32646,-32663,-32678,-32692,-32705,-32717,-
  32728,-32737,-32745,-32752,-32757,-32761,-32765,-32766,-
  32767,-32766,-32765,-32761,-32757,-32752,-32745,-32737,-
  32728,-32717,-32705,-32692,-32678,-32663,-32646,-32628,-
  32609,-32589,-32567,-32545,-32521,-32495,-32469,-32441,-
  32412,-32382,-32351,-32318,-32285,-32250,-32213,-32176,-
  32137,-32098,-32057,-32014,-31971,-31926,-31880,-31833,-
  31785,-31736,-31685,-31633,-31580,-31526,-31470,-31414,-
  31356,-31297,-31237,-31176,-31113,-31050,-30985,-30919,-
  30852,-30783,-30714,-30643,-30571,-30498,-30424,-30349,-
  30273,-30195,-30117,-30037,-29956,-29874,-29791,-29706,-
  29621,-29534,-29447,-29358,-29268,-29177,-29085,-28992,-
  28898,-28803,-28706,-28609,-28510,-28411,-28310,-28208,-
  28105,-28001,-27896,-27790,-27683,-27575,-27466,-27356,-
  27245,-27133,-27019,-26905,-26790,-26674,-26556,-26438,-
  26319,-26198,-26077,-25955,-25832,-25708,-25582,-25456,-
  25329,-25201,-25072,-24942,-24811,-24680,-24547,-24413,-
  24279,-24143,-24007,-23870,-23731,-23592,-23452,-23311,-
  23170,-23027,-22884,-22739,-22594,-22448,-22301,-22154,-
  22005,-21856,-21705,-21554,-21403,-21250,-21096,-20942,-
  20787,-20631,-20475,-20317,-20159,-20000,-19841,-19680,-
  19519,-19357,-19195,-19032,-18868,-18703,-18537,-18371,-
  18204,-18037,-17869,-17700,-17530,-17360,-17189,-17018,-
  16846,-16673,-16499,-16325,-16151,-15976,-15800,-15623,-
  15446,-15269,-15090,-14912,-14732,-14553,-14372,-14191,-
  14010,-13828,-13645,-13462,-13279,-13094,-12910,-12725,-
  12539,-12353,-12167,-11980,-11793,-11605,-11417,-11228,-
  11039,-10849,-10659,-10469,-10278,-10087,-9896,-9704,-
  9512,-9319,-9126,-8933,-8739,-8545,-8351,-8157,-
  7962,-7767,-7571,-7375,-7179,-6983,-6786,-6590,-
  6393,-6195,-5998,-5800,-5602,-5404,-5205,-5007,-
  4808,-4609,-4410,-4210,-4011,-3811,-3612,-3412,-
  3212,-3012,-2811,-2611,-2410,-2210,-2009,-1809,-
  1608,-1407,-1206,-1005,-804,-603,-402,-201
};

///////////////////////////////////////
//python generated bass-like waveform//
//Author: Andy Hu     2017/Feb/7     //
///////////////////////////////////////
const int16_t _bass[1024] = 
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-2,-2,-2,-2,-2,-2,-3,-3,-3,-3,-3,-4,-4,-4,-4,-5,-5,-5,-6,-6,-7,-7,-8,-8,-9,-9,-10,-10,-11,-12,-12,-13,-14,-15,-15,-16,-17,-18,-19,-20,-21,-23,-24,-25,-27,-28,-29,-31,-33,-34,-36,-38,-40,-42,-44,-47,-49,-51,-54,-57,-60,-62,-66,-69,-72,-75,-79,-83,-87,-91,-95,-100,-104,-109,-114,-119,-125,-130,-136,-142,-149,-155,-162,-169,-177,-184,-192,-201,-209,-218,-227,-237,-247,-257,-268,-279,-291,-303,-315,-328,-341,-355,-369,-383,-399,-414,-431,-447,-465,-483,-501,-521,-541,-561,-582,-604,-627,-650,-674,-699,-725,-751,-778,-807,-836,-866,-897,-928,-961,-995,-1030,-1066,-1103,-1141,-1180,-1220,-1262,-1304,-1348,-1394,-1440,-1488,-1537,-1588,-1640,-1693,-1748,-1804,-1862,-1922,-1983,-2046,-2110,-2176,-2244,-2313,-2385,-2458,-2533,-2610,-2689,-2770,-2853,-2938,-3025,-3115,-3206,-3300,-3396,-3494,-3594,-3697,-3802,-3910,-4020,-4133,-4248,-4366,-4486,-4609,-4735,-4863,-4995,-5129,-5266,-5405,-5548,-5694,-5842,-5994,-6149,-6306,-6467,-6631,-6798,-6969,-7143,-7319,-7500,-7683,-7870,-8060,-8254,-8451,-8651,-8855,-9063,-9274,-9488,-9706,-9927,-10152,-10380,-10612,-10848,-11087,-11329,-11576,-11825,-12078,-12335,-12595,-12858,-13125,-13395,-13669,-13946,-14226,-14510,-14797,-15086,-15379,-15676,-15975,-16276,-16581,-16889,-17199,-17512,-17827,-18145,-18465,-18787,-19111,-19437,-19765,-20094,-20425,-20758,-21091,-21426,-21761,-22097,-22434,-22771,-23108,-23444,-23780,-24116,-24451,-24784,-25117,-25447,-25775,-26102,-26425,-26746,-27063,-27376,-27686,-27991,-28292,-28587,-28876,-29160,-29437,-29707,-29969,-30224,-30470,-30707,-30934,-31152,-31358,-31554,-31737,-31908,-32065,-32209,-32338,-32451,-32549,-32629,-32692,-32737,-32762,-32766,-32750,-32712,-32651,-32566,-32456,-32320,-32158,-31967,-31747,-31497,-31216,-30901,-30554,-30171,-29751,-29294,-28798,-28261,-27683,-27061,-26395,-25682,-24921,-24111,-23249,-22335,-21366,-20341,-19258,-18114,-16909,-15640,-14305,-12902,-11429,-9884,-8265,-6569,-4795,-2940,-1001,1001,2940,4795,6569,8265,9884,11429,12902,14305,15640,16909,18114,19258,20341,21366,22335,23249,24111,24921,25682,26395,27061,27683,28261,28798,29294,29751,30171,30554,30901,31216,31497,31747,31967,32158,32320,32456,32566,32651,32712,32750,32767,32762,32737,32692,32629,32549,32451,32338,32209,32065,31908,31737,31554,31358,31152,30934,30707,30470,30224,29969,29707,29437,29160,28876,28587,28292,27991,27686,27376,27063,26746,26425,26102,25775,25447,25117,24784,24451,24116,23780,23444,23108,22771,22434,22097,21761,21426,21091,20758,20425,20094,19765,19437,19111,18787,18465,18145,17827,17512,17199,16889,16581,16276,15975,15676,15379,15086,14797,14510,14226,13946,13669,13395,13125,12858,12595,12335,12078,11825,11576,11329,11087,10848,10612,10380,10152,9927,9706,9488,9274,9063,8855,8651,8451,8254,8060,7870,7683,7500,7319,7143,6969,6798,6631,6467,6306,6149,5994,5842,5694,5548,5405,5266,5129,4995,4863,4735,4609,4486,4366,4248,4133,4020,3910,3802,3697,3594,3494,3396,3300,3206,3115,3025,2938,2853,2770,2689,2610,2533,2458,2385,2313,2244,2176,2110,2046,1983,1922,1862,1804,1748,1693,1640,1588,1537,1488,1440,1394,1348,1304,1262,1220,1180,1141,1103,1066,1030,995,961,928,897,866,836,807,778,751,725,699,674,650,627,604,582,561,541,521,501,483,465,447,431,414,399,383,369,355,341,328,315,303,291,279,268,257,247,237,227,218,209,201,192,184,177,169,162,155,149,142,136,130,125,119,114,109,104,100,95,91,87,83,79,75,72,69,66,62,60,57,54,51,49,47,44,42,40,38,36,34,33,31,29,28,27,25,24,23,21,20,19,18,17,16,15,15,14,13,12,12,11,10,10,9,9,8,8,7,7,6,6,5,5,5,4,4,4,4,3,3,3,3,3,2,2,2,2,2,2,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};