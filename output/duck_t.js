/* DUCK LANGUAGE PARSER AND GRAMMAR */
var GRAMMAR = {
  tokens: ["<epsilon>","<$>","<endl>","<integer>","<float>","<string>","<identifier>",",","import","include","module","endmodule","return","continue","break","throw","class","extends","endclass","func","endfunc","(",")","if","then","else","endif","for","=","to","do","step","in","while","loop","let","begin","end","try","catch","done","+=","-=","*=","/=","++","--","[","]",".","and","or","not","==","!=","<",">","<=",">=","is","+","-","*","/","mod","!","true","false",":"],
  symbols: ["<program>","<top-level-block>","<top-level-stmt>","<identifier-list>","<optendl>","<block>","<stmt>","<expr>","<assignment>","<self-assignment>","<class>","<function>","<if>","<for>","<while>","<let-block>","<try-block>","<parameters>","<class-ext>","<class-body>","<function-def>","<arguments>","<expr-list>","<condition>","<elseif>","<for-start>","<arithmetic>","<loop-end>","<value>","<bindings>","<binding>","<catch-block>","<l-value>","<object>","<logic>","<comparison>","<term>","<factor>","<primitive>","<array-init>","<dictionary-init>","<dictionary-entry>"],
  ruleSymbol: [0,1,2,2,4,4,5,5,3,3,3,3,6,6,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,11,19,19,20,12,12,21,18,18,18,22,22,23,23,13,25,25,25,14,26,26,26,26,15,15,28,16,30,30,31,17,32,32,9,9,10,10,10,10,10,10,33,33,33,8,24,24,24,35,35,36,36,36,36,36,36,36,36,36,27,27,27,37,37,37,37,38,38,38,29,29,29,29,39,39,39,39,39,34,34,34,40,40,41,41,42],
  ruleLen: [1,1,2,0,3,1,1,0,3,3,6,1,2,0,2,2,2,2,2,2,2,2,2,2,2,3,2,2,3,1,4,4,2,2,3,3,4,3,2,0,0,1,3,1,6,4,2,1,3,7,9,5,7,5,6,2,7,4,1,3,4,5,1,3,3,3,3,3,3,2,2,1,4,3,1,3,3,1,2,1,3,3,3,3,3,3,3,4,1,3,3,1,3,3,3,1,2,2,1,1,1,4,3,1,1,1,1,1,3,3,3,4,3,4,2,4],
  numRules: 116
};
var PARSER = {
  GOTO_TABLE: [],
  ACTION_TABLE: [],
  numTokens: 69,
  numSymbols: 42,
  numStates: 264
};
function _GOTO(data) {var index,seq;while(data.length){index=data.shift();seq=data.shift();if(typeof seq ==='number')PARSER.GOTO_TABLE[index]=seq;else while(seq.length)PARSER.GOTO_TABLE[index++]=seq.shift();}}
function _ACTION(data) {var index,seq;while(data.length){index=data.shift();seq=data.shift();if(typeof seq ==='number')PARSER.ACTION_TABLE[index]={'type':seq,'value':data.shift()};else while(seq.length)PARSER.ACTION_TABLE[index++]={'type':seq.shift(),'value':seq.shift()};}}
/* GOTO TABLE */
_GOTO([0,[1,2,3],6,[4,5,6,7,8,9,10,11,12,13,14],23,15,26,16,28,17,32,18,34,[19,20,21,22,23],127,[51,3],132,[4,5,6,7,8,9,10,11,12,13,14],149,15,152,16,154,17,158,18,160,[19,20,21,22,23],1263,86,1393,90,1409,15,1412,16,1414,17,1418,91,1420,[19,20,21,22,23],1519,95,1535,15,1538,16,1540,17,1544,91,1546,[19,20,21,22,23],1645,99,1661,15,1664,16,1666,17,1670,91,1672,[19,20,21,22,23],1703,100,1706,16,1708,17,1712,91,1714,[19,20,21,22,23],1829,103,1832,16,1834,17,1838,91,1840,[19,20,21,22,23],1877,[104,105],1958,16,1960,17,1964,91,1967,[108,21,22,23],2002,109,2006,91,2012,23,2044,110,2048,91,2054,23,2630,16,2632,17,2636,91,2638,[111,20,21,22,23],2672,16,2674,17,2678,91,2680,[112,20,21,22,23],2716,113,2720,91,2724,[114,22,23],2758,113,2762,91,2766,[115,22,23],2804,116,2821,118,2835,[119,120,15],2840,16,2842,17,2846,91,2848,[19,20,21,22,23],2863,122,2879,15,2882,16,2884,17,2888,[91,123,19,20,21,22,23],2924,125,2926,113,2930,91,2934,[21,22,23],2966,126,2968,113,2972,91,2976,[21,22,23],3008,127,3010,113,3014,91,3018,[21,22,23],3050,128,3052,113,3056,91,3060,[21,22,23],3176,129,3178,113,3182,91,3186,[21,22,23],3260,131,3262,113,3266,91,3270,[21,22,23],3302,132,3304,113,3308,91,3312,[21,22,23],3344,133,3346,113,3350,91,3354,[21,22,23],3386,134,3388,113,3392,91,3396,[21,22,23],3428,135,3430,113,3434,91,3438,[21,22,23],3470,136,3472,113,3476,91,3480,[21,22,23],3514,113,3518,91,3523,[137,23],3556,113,3560,91,3565,[138,23],3598,113,3602,91,3607,[139,23],4049,146,4091,149,4094,150,4133,149,4136,151,4267,154,4289,[158,159,5,6,7,8,9,10,11,12,13,14],4307,15,4310,16,4312,17,4316,18,4318,[19,20,21,22,23],4499,[165,159,5,6,7,8,9,10,11,12,13,14],4517,15,4520,16,4522,17,4526,18,4528,[19,20,21,22,23],4946,166,5212,169,5925,173,6011,[174,159,5,6,7,8,9,10,11,12,13,14],6029,15,6032,16,6034,17,6038,18,6040,[19,20,21,22,23],6150,175,6219,178,6578,183,6580,113,6584,91,6588,[21,22,23],6622,184,6626,91,6632,23,6683,[186,159,5,6,7,8,9,10,11,12,13,14],6701,15,6704,16,6706,17,6710,18,6712,[19,20,21,22,23],6850,189,6895,190,6911,15,6914,16,6916,17,6920,91,6922,[19,20,21,22,23],6961,191,7021,118,7036,[194,15],7040,16,7042,17,7046,91,7048,[19,20,21,22,23],7105,195,7121,15,7124,16,7126,17,7130,91,7132,[19,20,21,22,23,196,197,198],7397,[202,159,5,6,7,8,9,10,11,12,13,14],7411,203,7415,15,7418,16,7420,17,7424,18,7426,[19,20,21,22,23],7437,204,7565,[206,159,5,6,7,8,9,10,11,12,13,14],7583,15,7586,16,7588,17,7592,18,7594,[19,20,21,22,23],7607,[207,159,5,6,7,8,9,10,11,12,13,14],7625,15,7628,16,7630,17,7634,18,7636,[19,20,21,22,23],7859,[212,159,5,6,7,8,9,10,11,12,13,14],7877,15,7880,[16,213,17],7886,18,7888,[19,20,21,22,23],7967,[215,105],8096,216,8194,217,8718,226,8764,229,8768,91,8774,23,8804,230,8806,113,8810,91,8814,[21,22,23],8885,232,8888,16,8890,17,8894,91,8896,[19,20,21,22,23],8993,[234,159,5,6,7,8,9,10,11,12,13,14],9011,15,9014,16,9016,17,9020,18,9022,[19,20,21,22,23],9160,237,9202,238,9286,239,9413,[202,159,5,6,7,8,9,10,11,12,13,14],9427,240,9431,15,9434,16,9436,17,9440,18,9442,[19,20,21,22,23],9546,241,9707,[212,159,5,6,7,8,9,10,11,12,13,14],9725,15,9728,[16,246,17],9734,18,9736,[19,20,21,22,23],9875,[248,159,5,6,7,8,9,10,11,12,13,14],9893,15,9896,16,9898,17,9902,18,9904,[19,20,21,22,23],9961,195,9977,15,9980,16,9982,17,9986,91,9988,[19,20,21,22,23,249],10036,[250,198],10045,252,10061,15,10064,16,10066,17,10070,91,10072,[19,20,21,22,23],10169,[253,159,5,6,7,8,9,10,11,12,13,14],10187,15,10190,16,10192,17,10196,18,10198,[19,20,21,22,23],10316,256,10318,113,10322,91,10326,[21,22,23],10673,[212,159,5,6,7,8,9,10,11,12,13,14],10691,15,10694,[16,259,17],10700,18,10702,[19,20,21,22,23],10715,[212,159,5,6,7,8,9,10,11,12,13,14],10733,15,10736,[16,260,17],10742,18,10744,[19,20,21,22,23],11009,[212,159,5,6,7,8,9,10,11,12,13,14],11027,15,11030,[16,263,17],11036,18,11038,[19,20,21,22,23]]);

/* ACTION TABLE */
_ACTION([1,[2,3,1,25,1,26,1,27,1,28,1,29],8,[1,30,1,31,1,32],12,[1,33,1,34,1,35,1,36,1,37],19,1,38,21,1,39,23,1,40,27,1,41,30,1,42,33,1,43,35,1,44,38,1,45,52,1,46,61,1,47,65,[1,48,1,49,1,50],70,3,0,139,2,1,208,[2,3,1,25,1,26,1,27,1,28,1,29],215,[1,30,1,31,1,32],219,[1,33,1,34,1,35,1,36,1,37],226,1,38,228,1,39,230,1,40,234,1,41,237,1,42,240,1,43,242,1,44,245,1,45,259,1,46,268,1,47,272,[1,48,1,49,1,50],277,[2,11,2,11,2,11,2,11,2,11,2,11],284,[2,11,2,11,2,11],288,[2,11,2,11,2,11,2,11,2,11],295,2,11,297,2,11,299,2,11,303,2,11,306,2,11,309,2,11,311,2,11,314,2,11,328,2,11,337,2,11,341,[2,11,2,11,2,11],347,1,52,416,1,53,485,1,54,554,1,55,623,1,56,692,1,57,761,1,58,830,1,59,899,1,60,968,1,61,1037,2,74,1042,2,74,1057,2,74,1083,2,74,1085,[1,62,1,63],1106,2,88,1111,2,88,1126,2,88,1128,2,88,1134,2,88,1152,2,88,1154,[2,88,2,88],1157,[2,88,2,88,2,88,2,88,2,88,2,88],1164,[1,64,1,65],1175,2,98,1180,2,98,1195,2,98,1197,2,98,1202,[2,98,2,98,2,98],1221,2,98,1223,[2,98,2,98],1226,[2,98,2,98,2,98,2,98,2,98,2,98,1,66,2,98,2,98,2,98,2,98,2,98],1244,2,100,1249,2,100,1263,[1,67,2,100],1266,2,100,1270,[1,68,2,100,2,100,2,100],1283,[1,69,1,70,1,71,1,72,1,73,1,74,1,75,2,100,1,76,2,100,2,100],1295,[2,100,2,100,2,100,2,100,2,100,2,100,2,100,2,100,2,100,2,100,2,100,2,100],1313,2,77,1318,2,77,1333,2,77,1335,2,77,1341,2,77,1359,2,77,1361,[2,77,2,77],1382,2,79,1387,2,79,1402,2,79,1404,2,79,1410,2,79,1428,2,79,1430,[2,79,2,79],1433,[1,77,1,78,1,79,1,80,1,81,1,82],1451,2,91,1456,2,91,1471,2,91,1473,2,91,1478,[2,91,2,91,2,91],1497,2,91,1499,[2,91,2,91],1502,[2,91,2,91,2,91,2,91,2,91,2,91],1509,[2,91,2,91,1,83,1,84,1,85],1520,2,95,1525,2,95,1540,2,95,1542,2,95,1547,[2,95,2,95,2,95],1566,2,95,1568,[2,95,2,95],1571,[2,95,2,95,2,95,2,95,2,95,2,95],1578,[2,95,2,95,2,95,2,95,2,95],1589,2,99,1594,2,99,1609,2,99,1611,2,99,1616,[2,99,2,99,2,99],1635,2,99,1637,[2,99,2,99],1640,[2,99,2,99,2,99,2,99,2,99,2,99,2,99,2,99,2,99,2,99,2,99,2,99],1726,[2,29,2,29,2,29,2,29,2,29,2,29],1733,[2,29,2,29,2,29,2,29,2,29,2,29,2,29,2,29,2,29],1743,[2,29,2,29,2,29,2,29],1748,2,29,1750,[2,29,2,29,2,29],1755,2,29,1758,[2,29,2,29,2,29],1762,[2,29,2,29,2,29,2,29],1777,2,29,1786,2,29,1790,[2,29,2,29,2,29],1796,2,105,1801,2,105,1816,2,105,1818,2,105,1823,[2,105,2,105,2,105],1842,2,105,1844,[2,105,2,105],1847,[2,105,2,105,2,105,2,105,2,105,2,105,2,105,2,105,2,105,2,105,2,105,2,105],1865,2,106,1870,2,106,1885,2,106,1887,2,106,1892,[2,106,2,106,2,106],1911,2,106,1913,[2,106,2,106],1916,[2,106,2,106,2,106,2,106,2,106,2,106,2,106,2,106,2,106,2,106,2,106,2,106],1934,2,107,1939,2,107,1954,2,107,1956,2,107,1961,[2,107,2,107,2,107],1980,2,107,1982,[2,107,2,107],1985,[2,107,2,107,2,107,2,107,2,107,2,107,2,107,2,107,2,107,2,107,2,107,2,107],2003,2,71,2008,2,71,2022,[2,71,2,71],2025,2,71,2029,[2,71,2,71,2,71,2,71],2042,[2,71,2,71,2,71,2,71,2,71,2,71,2,71,2,71,2,71,2,71,2,71],2054,[2,71,2,71,2,71,2,71,2,71,2,71,2,71,2,71,2,71,2,71,2,71,2,71],2076,1,87,2144,1,88,2214,1,89,2279,[1,92,1,26,1,27,1,28,1,29],2298,1,39,2329,1,46,2338,1,47,2342,[1,48,1,49,1,50],2348,1,93,2417,1,94,2487,[1,26,1,27,1,28,1,29],2505,1,39,2536,1,46,2545,1,47,2549,[1,48,1,49,1,50],2559,1,96,2627,[1,97,1,98],2694,[1,26,1,27,1,28,1,29],2712,1,39,2743,1,46,2752,1,47,2756,[1,48,1,49,1,50],2763,[1,26,1,27,1,28,1,29],2781,1,39,2812,1,46,2821,1,47,2825,[1,48,1,49,1,50],2835,1,101,2900,1,102,2970,[1,26,1,27,1,28,1,29],2988,1,39,3019,1,46,3028,1,47,3032,[1,48,1,49,1,50],3042,1,106,3107,1,107,3177,[1,26,1,27,1,28,1,29],3195,1,39,3235,1,47,3239,[1,48,1,49,1,50],3246,[1,26,1,27,1,28,1,29],3264,1,39,3309,[1,49,1,50],3315,[1,26,1,27,1,28,1,29],3333,1,39,3378,[1,49,1,50],3383,2,103,3388,2,103,3403,2,103,3405,2,103,3410,[2,103,2,103,2,103],3429,2,103,3431,[2,103,2,103],3434,[2,103,2,103,2,103,2,103,2,103,2,103,2,103,2,103,2,103,2,103,2,103,2,103],3452,2,104,3457,2,104,3472,2,104,3474,2,104,3479,[2,104,2,104,2,104],3498,2,104,3500,[2,104,2,104],3503,[2,104,2,104,2,104,2,104,2,104,2,104,2,104,2,104,2,104,2,104,2,104,2,104],3520,2,2,3589,[2,14,2,14,2,14,2,14,2,14,2,14],3596,[2,14,2,14,2,14,2,14,2,14,2,14,2,14,2,14,2,14],3606,[2,14,2,14,2,14,2,14],3611,2,14,3613,[2,14,2,14,2,14],3618,2,14,3621,[2,14,2,14,2,14],3625,[2,14,2,14,2,14,2,14],3640,2,14,3649,2,14,3653,[2,14,2,14,2,14],3658,[2,15,2,15,2,15,2,15,2,15,2,15],3665,[2,15,2,15,2,15,2,15,2,15,2,15,2,15,2,15,2,15],3675,[2,15,2,15,2,15,2,15],3680,2,15,3682,[2,15,2,15,2,15],3687,2,15,3690,[2,15,2,15,2,15],3694,[2,15,2,15,2,15,2,15],3709,2,15,3718,2,15,3722,[2,15,2,15,2,15],3727,[2,16,2,16,2,16,2,16,2,16,2,16],3734,[2,16,2,16,2,16,2,16,2,16,2,16,2,16,2,16,2,16],3744,[2,16,2,16,2,16,2,16],3749,2,16,3751,[2,16,2,16,2,16],3756,2,16,3759,[2,16,2,16,2,16],3763,[2,16,2,16,2,16,2,16],3778,2,16,3787,2,16,3791,[2,16,2,16,2,16],3796,[2,17,2,17,2,17,2,17,2,17,2,17],3803,[2,17,2,17,2,17,2,17,2,17,2,17,2,17,2,17,2,17],3813,[2,17,2,17,2,17,2,17],3818,2,17,3820,[2,17,2,17,2,17],3825,2,17,3828,[2,17,2,17,2,17],3832,[2,17,2,17,2,17,2,17],3847,2,17,3856,2,17,3860,[2,17,2,17,2,17],3865,[2,18,2,18,2,18,2,18,2,18,2,18],3872,[2,18,2,18,2,18,2,18,2,18,2,18,2,18,2,18,2,18],3882,[2,18,2,18,2,18,2,18],3887,2,18,3889,[2,18,2,18,2,18],3894,2,18,3897,[2,18,2,18,2,18],3901,[2,18,2,18,2,18,2,18],3916,2,18,3925,2,18,3929,[2,18,2,18,2,18],3934,[2,19,2,19,2,19,2,19,2,19,2,19],3941,[2,19,2,19,2,19,2,19,2,19,2,19,2,19,2,19,2,19],3951,[2,19,2,19,2,19,2,19],3956,2,19,3958,[2,19,2,19,2,19],3963,2,19,3966,[2,19,2,19,2,19],3970,[2,19,2,19,2,19,2,19],3985,2,19,3994,2,19,3998,[2,19,2,19,2,19],4003,[2,20,2,20,2,20,2,20,2,20,2,20],4010,[2,20,2,20,2,20,2,20,2,20,2,20,2,20,2,20,2,20],4020,[2,20,2,20,2,20,2,20],4025,2,20,4027,[2,20,2,20,2,20],4032,2,20,4035,[2,20,2,20,2,20],4039,[2,20,2,20,2,20,2,20],4054,2,20,4063,2,20,4067,[2,20,2,20,2,20],4072,[2,21,2,21,2,21,2,21,2,21,2,21],4079,[2,21,2,21,2,21,2,21,2,21,2,21,2,21,2,21,2,21],4089,[2,21,2,21,2,21,2,21],4094,2,21,4096,[2,21,2,21,2,21],4101,2,21,4104,[2,21,2,21,2,21],4108,[2,21,2,21,2,21,2,21],4123,2,21,4132,2,21,4136,[2,21,2,21,2,21],4141,[2,22,2,22,2,22,2,22,2,22,2,22],4148,[2,22,2,22,2,22,2,22,2,22,2,22,2,22,2,22,2,22],4158,[2,22,2,22,2,22,2,22],4163,2,22,4165,[2,22,2,22,2,22],4170,2,22,4173,[2,22,2,22,2,22],4177,[2,22,2,22,2,22,2,22],4192,2,22,4201,2,22,4205,[2,22,2,22,2,22],4210,[2,23,2,23,2,23,2,23,2,23,2,23],4217,[2,23,2,23,2,23,2,23,2,23,2,23,2,23,2,23,2,23],4227,[2,23,2,23,2,23,2,23],4232,2,23,4234,[2,23,2,23,2,23],4239,2,23,4242,[2,23,2,23,2,23],4246,[2,23,2,23,2,23,2,23],4261,2,23,4270,2,23,4274,[2,23,2,23,2,23],4281,[1,26,1,27,1,28,1,29],4299,1,39,4330,1,46,4339,1,47,4343,[1,48,1,49,1,50],4350,[1,26,1,27,1,28,1,29],4368,1,39,4399,1,46,4408,1,47,4412,[1,48,1,49,1,50],4419,[1,26,1,27,1,28,1,29],4437,1,39,4477,1,47,4481,[1,48,1,49,1,50],4488,[1,26,1,27,1,28,1,29],4506,1,39,4546,1,47,4550,[1,48,1,49,1,50],4560,1,29,4606,1,117,4626,[1,26,1,27,1,28,1,29],4644,[1,39,2,40],4675,1,46,4684,1,47,4688,[1,48,1,49,1,50],4695,[1,26,1,27,1,28,1,29],4713,1,39,4739,1,124,4744,1,46,4753,1,47,4757,[1,48,1,49,1,50],4764,[1,26,1,27,1,28,1,29],4782,1,39,4822,1,47,4826,[1,48,1,49,1,50],4833,[1,26,1,27,1,28,1,29],4851,1,39,4891,1,47,4895,[1,48,1,49,1,50],4902,[1,26,1,27,1,28,1,29],4920,1,39,4960,1,47,4964,[1,48,1,49,1,50],4971,[1,26,1,27,1,28,1,29],4989,1,39,5029,1,47,5033,[1,48,1,49,1,50],5039,2,69,5108,2,70,5178,[1,26,1,27,1,28,1,29],5196,1,39,5236,1,47,5240,[1,48,1,49,1,50],5250,1,130,5316,[1,26,1,27,1,28,1,29],5334,1,39,5374,1,47,5378,[1,48,1,49,1,50],5385,[1,26,1,27,1,28,1,29],5403,1,39,5443,1,47,5447,[1,48,1,49,1,50],5454,[1,26,1,27,1,28,1,29],5472,1,39,5512,1,47,5516,[1,48,1,49,1,50],5523,[1,26,1,27,1,28,1,29],5541,1,39,5581,1,47,5585,[1,48,1,49,1,50],5592,[1,26,1,27,1,28,1,29],5610,1,39,5650,1,47,5654,[1,48,1,49,1,50],5661,[1,26,1,27,1,28,1,29],5679,1,39,5719,1,47,5723,[1,48,1,49,1,50],5730,[1,26,1,27,1,28,1,29],5748,1,39,5788,1,47,5792,[1,48,1,49,1,50],5799,[1,26,1,27,1,28,1,29],5817,1,39,5857,1,47,5861,[1,48,1,49,1,50],5868,[1,26,1,27,1,28,1,29],5886,1,39,5926,1,47,5930,[1,48,1,49,1,50],5936,1,140,6005,2,5,6010,1,141,6025,2,5,6074,1,142,6143,1,143,6212,1,144,6281,2,100,6286,2,100,6300,[1,67,2,100],6303,2,100,6308,[2,100,2,100,2,100],6326,[1,75,2,100,1,76,2,100,2,100],6332,[2,100,2,100,2,100,2,100,2,100,2,100,2,100,2,100,2,100,2,100,2,100,2,100],6349,[2,24,2,24,2,24,2,24,2,24,2,24],6356,[2,24,2,24,2,24,2,24,2,24,2,24,2,24,2,24,2,24],6366,[2,24,2,24,2,24,2,24],6371,2,24,6373,[2,24,2,24,2,24],6378,2,24,6381,[2,24,2,24,2,24],6385,[2,24,2,24,2,24,2,24],6400,2,24,6409,2,24,6413,[2,24,2,24,2,24],6418,[2,26,2,26,2,26,2,26,2,26,2,26],6425,[2,26,2,26,2,26,2,26,2,26,2,26,2,26,2,26,2,26],6435,[2,26,2,26,2,26,2,26],6440,2,26,6442,[2,26,2,26,2,26],6447,2,26,6450,[2,26,2,26,2,26],6454,[2,26,2,26,2,26,2,26],6469,2,26,6478,2,26,6482,[2,26,2,26,2,26],6487,[2,27,2,27,2,27,2,27,2,27,2,27],6494,[2,27,2,27,2,27,2,27,2,27,2,27,2,27,2,27,2,27],6504,[2,27,2,27,2,27,2,27],6509,2,27,6511,[2,27,2,27,2,27],6516,2,27,6519,[2,27,2,27,2,27],6523,[2,27,2,27,2,27,2,27],6538,2,27,6547,2,27,6551,[2,27,2,27,2,27],6557,1,145,6626,2,39,6641,2,39,6645,1,148,6695,2,39,6710,2,39,6714,1,148,6764,2,39,6779,2,39,6783,1,148,6853,1,152,6924,1,153,6950,[1,62,1,63],6976,1,155,6997,1,156,7001,1,157,7040,[1,25,1,26,1,27,1,28,1,29],7049,[2,13,1,33,1,34,1,35,1,36,1,37],7056,[2,13,1,38,2,13,1,39],7061,1,40,7063,[2,13,2,13,1,41],7068,1,42,7071,[1,43,2,13,1,44],7075,[2,13,1,45,2,13,2,13],7090,1,46,7099,1,47,7103,[1,48,1,49,1,50],7137,1,161,7157,[1,62,1,63],7178,1,162,7247,2,58,7252,1,163,7342,1,164,7385,[1,25,1,26,1,27,1,28,1,29],7394,[2,13,1,33,1,34,1,35,1,36,1,37],7401,[2,13,1,38,2,13,1,39],7406,1,40,7408,[2,13,2,13,1,41],7413,1,42,7416,[1,43,2,13,1,44],7420,[2,13,1,45,2,13,2,13],7435,1,46,7444,1,47,7448,[1,48,1,49,1,50],7454,2,78,7459,2,78,7474,2,78,7476,2,78,7482,2,78,7500,2,78,7502,[2,78,2,78],7505,[1,77,1,78,1,79,1,80,1,81,1,82],7523,2,96,7528,2,96,7543,2,96,7545,2,96,7550,[2,96,2,96,2,96],7569,2,96,7571,[2,96,2,96],7574,[2,96,2,96,2,96,2,96,2,96,2,96],7581,[2,96,2,96,2,96,2,96,2,96],7592,2,97,7597,2,97,7612,2,97,7614,2,97,7619,[2,97,2,97,2,97],7638,2,97,7640,[2,97,2,97],7643,[2,97,2,97,2,97,2,97,2,97,2,97],7650,[2,97,2,97,2,97,2,97,2,97],7661,2,75,7666,2,75,7681,2,75,7683,2,75,7689,2,75,7707,2,75,7709,[2,75,2,75],7730,2,76,7735,2,76,7750,2,76,7752,2,76,7758,2,76,7776,2,76,7778,[2,76,2,76],7799,2,98,7804,2,98,7819,2,98,7821,2,98,7826,[2,98,2,98,2,98],7845,2,98,7847,[2,98,2,98],7850,[2,98,2,98,2,98,2,98,2,98,2,98],7857,[2,98,2,98,2,98,2,98,2,98],7868,2,89,7873,2,89,7888,2,89,7890,2,89,7895,[2,89,2,89,2,89],7914,2,89,7916,[2,89,2,89],7919,[2,89,2,89,2,89,2,89,2,89,2,89],7926,[2,89,2,89,1,83,1,84,1,85],7937,2,90,7942,2,90,7957,2,90,7959,2,90,7964,[2,90,2,90,2,90],7983,2,90,7985,[2,90,2,90],7988,[2,90,2,90,2,90,2,90,2,90,2,90],7995,[2,90,2,90,1,83,1,84,1,85],8006,2,86,8011,2,86,8026,2,86,8028,2,86,8034,2,86,8051,[1,75,2,86,1,76,2,86,2,86],8057,[2,86,2,86,2,86,2,86,2,86,2,86],8079,1,29,8149,1,167,8164,2,43,8233,1,168,8302,2,41,8420,2,63,8489,2,64,8558,[1,171,2,7,2,7,2,7,2,7],8577,2,7,8604,2,7,8608,2,7,8617,2,7,8621,[2,7,2,7,2,7],8627,2,65,8685,[1,64,1,65],8696,2,66,8754,[1,64,1,65],8765,2,67,8823,[1,64,1,65],8834,2,68,8892,[1,64,1,65],8949,1,172,8961,[1,64,1,65],8972,2,73,8977,2,73,8991,[2,73,2,73],8994,2,73,8998,[2,73,2,73,2,73,2,73],9011,[2,73,2,73,2,73,2,73,2,73,2,73,2,73,2,73,2,73,2,73,2,73],9023,[2,73,2,73,2,73,2,73,2,73,2,73,2,73,2,73,2,73,2,73,2,73,2,73],9041,2,80,9046,2,80,9061,2,80,9063,2,80,9069,2,80,9087,2,80,9089,[2,80,2,80],9092,[2,80,2,80,2,80,2,80,2,80,2,80],9099,[1,64,1,65],9110,2,81,9115,2,81,9130,2,81,9132,2,81,9138,2,81,9156,2,81,9158,[2,81,2,81],9161,[2,81,2,81,2,81,2,81,2,81,2,81],9168,[1,64,1,65],9179,2,82,9184,2,82,9199,2,82,9201,2,82,9207,2,82,9225,2,82,9227,[2,82,2,82],9230,[2,82,2,82,2,82,2,82,2,82,2,82],9237,[1,64,1,65],9248,2,83,9253,2,83,9268,2,83,9270,2,83,9276,2,83,9294,2,83,9296,[2,83,2,83],9299,[2,83,2,83,2,83,2,83,2,83,2,83],9306,[1,64,1,65],9317,2,84,9322,2,84,9337,2,84,9339,2,84,9345,2,84,9363,2,84,9365,[2,84,2,84],9368,[2,84,2,84,2,84,2,84,2,84,2,84],9375,[1,64,1,65],9386,2,85,9391,2,85,9406,2,85,9408,2,85,9414,2,85,9432,2,85,9434,[2,85,2,85],9437,[2,85,2,85,2,85,2,85,2,85,2,85],9444,[1,64,1,65],9455,2,92,9460,2,92,9475,2,92,9477,2,92,9482,[2,92,2,92,2,92],9501,2,92,9503,[2,92,2,92],9506,[2,92,2,92,2,92,2,92,2,92,2,92],9513,[2,92,2,92,2,92,2,92,2,92],9524,2,93,9529,2,93,9544,2,93,9546,2,93,9551,[2,93,2,93,2,93],9570,2,93,9572,[2,93,2,93],9575,[2,93,2,93,2,93,2,93,2,93,2,93],9582,[2,93,2,93,2,93,2,93,2,93],9593,2,94,9598,2,94,9613,2,94,9615,2,94,9620,[2,94,2,94,2,94],9639,2,94,9641,[2,94,2,94],9644,[2,94,2,94,2,94,2,94,2,94,2,94],9651,[2,94,2,94,2,94,2,94,2,94],9661,[2,8,2,8,2,8,2,8,2,8,2,8],9668,[2,8,2,8,2,8],9672,[2,8,2,8,2,8,2,8,2,8],9679,2,8,9681,2,8,9683,2,8,9687,2,8,9690,2,8,9693,2,8,9695,2,8,9698,2,8,9712,2,8,9721,2,8,9725,[2,8,2,8,2,8],9735,1,87,9799,[2,9,2,9,2,9,2,9,2,9,2,9],9806,[2,9,2,9,2,9],9810,[2,9,2,9,2,9,2,9,2,9],9817,2,9,9819,2,9,9821,2,9,9825,2,9,9828,2,9,9831,2,9,9833,2,9,9836,2,9,9850,2,9,9859,2,9,9863,[2,9,2,9,2,9],9869,[1,25,1,26,1,27,1,28,1,29],9878,[2,13,1,33,1,34,1,35,1,36,1,37],9885,[2,13,1,38,2,13,1,39],9890,1,40,9892,[2,13,2,13,1,41],9897,1,42,9900,[1,43,2,13,1,44],9904,[2,13,1,45,2,13,2,13],9919,1,46,9928,1,47,9932,[1,48,1,49,1,50],9937,[2,25,2,25,2,25,2,25,2,25,2,25],9944,[2,25,2,25,2,25,2,25,2,25,2,25,2,25,2,25,2,25],9954,[2,25,2,25,2,25,2,25],9959,2,25,9961,[2,25,2,25,2,25],9966,2,25,9969,[2,25,2,25,2,25],9973,[2,25,2,25,2,25,2,25],9988,2,25,9997,2,25,10001,[2,25,2,25,2,25],10006,[2,28,2,28,2,28,2,28,2,28,2,28],10013,[2,28,2,28,2,28,2,28,2,28,2,28,2,28,2,28,2,28],10023,[2,28,2,28,2,28,2,28],10028,2,28,10030,[2,28,2,28,2,28],10035,2,28,10038,[2,28,2,28,2,28],10042,[2,28,2,28,2,28,2,28],10057,2,28,10066,2,28,10070,[2,28,2,28,2,28],10076,1,176,10091,1,177,10218,1,87,10234,1,179,10283,1,180,10352,2,35,10421,2,34,10490,2,102,10495,2,102,10510,2,102,10512,2,102,10517,[2,102,2,102,2,102],10536,2,102,10538,[2,102,2,102],10541,[2,102,2,102,2,102,2,102,2,102,2,102,2,102,2,102,2,102,2,102,2,102,2,102],10559,1,181,10628,2,48,10701,1,182,10767,[1,26,1,27,1,28,1,29],10785,1,39,10825,1,47,10829,[1,48,1,49,1,50],10836,[1,26,1,27,1,28,1,29],10854,1,39,10899,[1,49,1,50],10936,1,185,10973,[1,25,1,26,1,27,1,28,1,29],10982,[2,13,1,33,1,34,1,35,1,36,1,37],10989,[2,13,1,38,2,13,1,39],10994,1,40,10996,[2,13,2,13,1,41],11001,1,42,11004,[1,43,2,13,1,44],11008,[2,13,1,45,2,13,2,13],11023,1,46,11032,1,47,11036,[1,48,1,49,1,50],11111,1,187,11214,1,188,11249,[1,171,2,7,2,7,2,7,2,7],11268,2,7,11295,2,7,11299,2,7,11308,2,7,11312,[2,7,2,7,2,7],11319,[1,26,1,27,1,28,1,29],11337,1,39,11368,1,46,11377,1,47,11381,[1,48,1,49,1,50],11424,[1,192,1,193],11456,2,87,11461,2,87,11476,2,87,11478,2,87,11484,2,87,11501,[1,75,2,87,1,76,2,87,2,87],11507,[2,87,2,87,2,87,2,87,2,87,2,87],11526,[1,26,1,27,1,28,1,29],11544,1,39,11575,1,46,11584,1,47,11588,[1,48,1,49,1,50],11594,2,101,11599,2,101,11614,2,101,11616,2,101,11621,[2,101,2,101,2,101],11640,2,101,11642,[2,101,2,101],11645,[2,101,2,101,2,101,2,101,2,101,2,101,2,101,2,101,2,101,2,101,2,101,2,101],11664,[1,26,1,27,1,28,1,199],11682,1,39,11709,1,200,11713,1,46,11722,1,47,11726,[1,48,1,49,1,50],11802,[2,6,2,6,2,6,2,6],11820,2,6,11847,2,6,11851,2,6,11860,2,6,11864,[2,6,2,6,2,6],11870,2,72,11875,2,72,11889,[2,72,2,72],11892,2,72,11896,[2,72,2,72,2,72,2,72],11909,[2,72,2,72,2,72,2,72,2,72,2,72,2,72,2,72,2,72,2,72,2,72],11921,[2,72,2,72,2,72,2,72,2,72,2,72,2,72,2,72,2,72,2,72,2,72,2,72],11939,2,4,11959,2,4,12017,1,201,12077,2,30,12146,[1,25,1,26,1,27,1,28,1,29],12155,[2,13,1,33,1,34,1,35,1,36,1,37],12162,[2,13,1,38,2,13,1,39],12167,1,40,12169,[2,13,2,13,1,41],12174,1,42,12177,[1,43,2,13,1,44],12181,[2,13,1,45,2,13,2,13],12196,1,46,12205,1,47,12209,[1,48,1,49,1,50],12219,1,87,12304,1,205,12353,2,38,12368,2,38,12422,[1,25,1,26,1,27,1,28,1,29],12431,[2,13,1,33,1,34,1,35,1,36,1,37],12438,[2,13,1,38,2,13,1,39],12443,1,40,12445,[2,13,2,13,1,41],12450,1,42,12453,[1,43,2,13,1,44],12457,[2,13,1,45,2,13,2,13],12472,1,46,12481,1,47,12485,[1,48,1,49,1,50],12491,[1,25,1,26,1,27,1,28,1,29],12500,[2,13,1,33,1,34,1,35,1,36,1,37],12507,[2,13,1,38,2,13,1,39],12512,1,40,12514,[2,13,2,13,1,41],12519,1,42,12522,[1,43,2,13,1,44],12526,[2,13,1,45,2,13,2,13],12541,1,46,12550,1,47,12554,[1,48,1,49,1,50],12590,1,208,12656,1,209,12687,[1,64,1,65],12726,1,210,12798,1,211,12845,2,12,12852,2,12,12854,2,12,12859,[2,12,2,12],12868,2,12,12871,2,12,12873,[2,12,2,12],12905,[1,25,1,26,1,27,1,28,1,29],12914,[2,13,1,33,1,34,1,35,1,36,1,37],12921,[2,13,1,38,2,13,1,39],12926,1,40,12928,[2,13,2,13,1,41],12933,1,42,12936,[1,43,2,13,1,44],12940,[2,13,1,45,2,13,2,13],12955,1,46,12964,1,47,12968,[1,48,1,49,1,50],12974,1,214,13047,1,106,13112,2,59,13117,2,59,13181,2,60,13254,1,29,13319,2,62,13408,2,42,13457,[1,171,2,7,2,7,2,7,2,7,1,218],13476,2,7,13503,2,7,13507,2,7,13516,2,7,13520,[2,7,2,7,2,7],13526,2,109,13595,2,110,13669,1,219,13710,1,220,13733,2,71,13738,2,71,13752,[2,71,2,71],13755,2,71,13759,[2,71,2,71,2,71,2,71],13772,[2,71,2,71,2,71,2,71,2,71,2,71,2,71,2,71,2,71,2,71,2,71],13784,[2,71,2,71,2,71,2,71,2,71,2,71,2,71,2,71,2,71,2,71,2,71,2,71],13799,1,221,13802,2,108,13871,1,222,13956,1,223,14009,2,32,14078,1,224,14147,2,37,14162,2,37,14234,1,225,14308,[1,227,1,228],14355,[1,26,1,27,1,28,1,29],14373,1,39,14418,[1,49,1,50],14424,[1,26,1,27,1,28,1,29],14442,1,39,14482,1,47,14486,[1,48,1,49,1,50],14492,1,231,14562,[1,26,1,27,1,28,1,29],14580,1,39,14611,1,46,14620,1,47,14624,[1,48,1,49,1,50],14662,1,233,14699,2,53,14768,[1,25,1,26,1,27,1,28,1,29],14777,[2,13,1,33,1,34,1,35,1,36,1,37],14784,[2,13,1,38,2,13,1,39],14789,1,40,14791,[2,13,2,13,1,41],14796,1,42,14799,[1,43,2,13,1,44],14803,[2,13,1,45,2,13,2,13],14818,1,46,14827,1,47,14831,[1,48,1,49,1,50],14837,2,57,14906,1,235,14951,1,75,14953,1,76,15021,1,236,15044,[1,171,2,7,2,7,2,7,2,7],15063,2,7,15090,2,7,15094,2,7,15103,2,7,15107,[2,7,2,7,2,7],15113,[1,171,2,7,2,7,2,7,2,7],15132,2,7,15159,2,7,15163,2,7,15172,2,7,15176,[2,7,2,7,2,7],15182,2,114,15251,[1,171,2,7,2,7,2,7,2,7],15270,2,7,15297,2,7,15301,2,7,15310,2,7,15314,[2,7,2,7,2,7],15319,[2,10,2,10,2,10,2,10,2,10,2,10],15326,[2,10,2,10,2,10],15330,[2,10,2,10,2,10,2,10,2,10],15337,2,10,15339,2,10,15341,2,10,15345,2,10,15348,2,10,15351,2,10,15353,2,10,15356,2,10,15370,2,10,15379,2,10,15383,[2,10,2,10,2,10],15389,2,33,15458,[1,25,1,26,1,27,1,28,1,29],15467,[2,13,1,33,1,34,1,35,1,36,1,37],15474,[2,13,1,38,2,13,1,39],15479,1,40,15481,[2,13,2,13,1,41],15486,1,42,15489,[1,43,2,13,1,44],15493,[2,13,1,45,2,13,2,13],15508,1,46,15517,1,47,15521,[1,48,1,49,1,50],15527,2,36,15596,2,44,15665,1,242,15686,1,40,15734,2,47,15831,1,243,15900,[1,244,1,245],15930,[1,64,1,65],15941,[1,25,1,26,1,27,1,28,1,29],15950,[2,13,1,33,1,34,1,35,1,36,1,37],15957,[2,13,1,38,2,13,1,39],15962,1,40,15964,[2,13,2,13,1,41],15969,1,42,15972,[1,43,2,13,1,44],15976,[2,13,1,45,2,13,2,13],15991,1,46,16000,1,47,16004,[1,48,1,49,1,50],16010,2,54,16058,[1,62,1,63],16079,2,55,16183,1,247,16217,[1,25,1,26,1,27,1,28,1,29],16226,[2,13,1,33,1,34,1,35,1,36,1,37],16233,[2,13,1,38,2,13,1,39],16238,1,40,16240,[2,13,2,13,1,41],16245,1,42,16248,[1,43,2,13,1,44],16252,[2,13,1,45,2,13,2,13],16267,1,46,16276,1,47,16280,[1,48,1,49,1,50],16286,2,112,16356,[1,26,1,27,1,28,1,29],16374,1,39,16405,1,46,16414,1,47,16418,[1,48,1,49,1,50],16428,1,251,16494,[1,26,1,27,1,28,1,29],16512,1,39,16543,1,46,16552,1,47,16556,[1,48,1,49,1,50],16562,2,31,16631,2,46,16700,[1,25,1,26,1,27,1,28,1,29],16709,[2,13,1,33,1,34,1,35,1,36,1,37],16716,[2,13,1,38,2,13,1,39],16721,1,40,16723,[2,13,2,13,1,41],16728,1,42,16731,[1,43,2,13,1,44],16735,[2,13,1,45,2,13,2,13],16750,1,46,16759,1,47,16763,[1,48,1,49,1,50],16769,1,254,16838,1,255,16908,[1,26,1,27,1,28,1,29],16926,1,39,16966,1,47,16970,[1,48,1,49,1,50],16976,2,51,17045,2,56,17152,1,257,17183,2,111,17252,2,113,17387,1,221,17395,2,115,17436,2,115,17483,1,258,17528,[1,25,1,26,1,27,1,28,1,29],17537,[2,13,1,33,1,34,1,35,1,36,1,37],17544,[2,13,1,38,2,13,1,39],17549,1,40,17551,[2,13,2,13,1,41],17556,1,42,17559,[1,43,2,13,1,44],17563,[2,13,1,45,2,13,2,13],17578,1,46,17587,1,47,17591,[1,48,1,49,1,50],17597,[1,25,1,26,1,27,1,28,1,29],17606,[2,13,1,33,1,34,1,35,1,36,1,37],17613,[2,13,1,38,2,13,1,39],17618,1,40,17620,[2,13,2,13,1,41],17625,1,42,17628,[1,43,2,13,1,44],17632,[2,13,1,45,2,13,2,13],17647,1,46,17656,1,47,17660,[1,48,1,49,1,50],17694,1,261,17724,[1,64,1,65],17735,2,61,17804,2,45,17873,2,52,17942,2,49,18011,1,262,18080,[1,25,1,26,1,27,1,28,1,29],18089,[2,13,1,33,1,34,1,35,1,36,1,37],18096,[2,13,1,38,2,13,1,39],18101,1,40,18103,[2,13,2,13,1,41],18108,1,42,18111,[1,43,2,13,1,44],18115,[2,13,1,45,2,13,2,13],18130,1,46,18139,1,47,18143,[1,48,1,49,1,50],18149,2,50]);
