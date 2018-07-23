#include "opencv2/opencv.hpp"
#include <string>
#include <iostream>
#include <fstream>
#include <cstdio>
#include <vector> 
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include "opencv2/imgcodecs.hpp"
#include <opencv2/highgui.hpp>
#include <opencv2/ml.hpp>

using namespace cv;
using namespace std;

String record = "C:\\Users\\yozorasa\\Documents\\GraduateSchool\\space\\lbp\\";
String loadLocation = record + "lbp\\";
String loadLocation2 = record + "lbp_notCloud\\";

fstream file;

int cloudAmount = 497;
int otherAmount = 251;
float histogram[748][256] = { 0 };
int tag[748] = { 0 };
String cloudFileName[994] = {
	"1_106_lbp.jpg",
	"1_106_roi.jpg",
	"1_116_lbp.jpg",
	"1_116_roi.jpg",
	"1_117_lbp.jpg",
	"1_117_roi.jpg",
	"1_135_lbp.jpg",
	"1_135_roi.jpg",
	"2_200_lbp.jpg",
	"2_200_roi.jpg",
	"2_46_lbp.jpg",
	"2_46_roi.jpg",
	"3_20_lbp.jpg",
	"3_20_roi.jpg",
	"4_11_lbp.jpg",
	"4_11_roi.jpg",
	"4_7_lbp.jpg",
	"4_7_roi.jpg",
	"453_155_lbp.jpg",
	"453_155_roi.jpg",
	"453_220_lbp.jpg",
	"453_220_roi.jpg",
	"453_221_lbp.jpg",
	"453_221_roi.jpg",
	"453_233_lbp.jpg",
	"453_233_roi.jpg",
	"453_250_lbp.jpg",
	"453_250_roi.jpg",
	"453_256_lbp.jpg",
	"453_256_roi.jpg",
	"453_258_lbp.jpg",
	"453_258_roi.jpg",
	"453_270_lbp.jpg",
	"453_270_roi.jpg",
	"453_272_lbp.jpg",
	"453_272_roi.jpg",
	"453_273_lbp.jpg",
	"453_273_roi.jpg",
	"453_276_lbp.jpg",
	"453_276_roi.jpg",
	"453_306_lbp.jpg",
	"453_306_roi.jpg",
	"453_359_lbp.jpg",
	"453_359_roi.jpg",
	"453_360_lbp.jpg",
	"453_360_roi.jpg",
	"453_381_lbp.jpg",
	"453_381_roi.jpg",
	"453_706_lbp.jpg",
	"453_706_roi.jpg",
	"453_764_lbp.jpg",
	"453_764_roi.jpg",
	"453_771_lbp.jpg",
	"453_771_roi.jpg",
	"454_135_lbp.jpg",
	"454_135_roi.jpg",
	"454_151_lbp.jpg",
	"454_151_roi.jpg",
	"454_444_lbp.jpg",
	"454_444_roi.jpg",
	"456_1189_lbp.jpg",
	"456_1189_roi.jpg",
	"456_1190_lbp.jpg",
	"456_1190_roi.jpg",
	"456_1268_lbp.jpg",
	"456_1268_roi.jpg",
	"456_1272_lbp.jpg",
	"456_1272_roi.jpg",
	"456_1283_lbp.jpg",
	"456_1283_roi.jpg",
	"456_1287_lbp.jpg",
	"456_1287_roi.jpg",
	"456_192_lbp.jpg",
	"456_192_roi.jpg",
	"456_359_lbp.jpg",
	"456_359_roi.jpg",
	"456_584_lbp.jpg",
	"456_584_roi.jpg",
	"456_744_lbp.jpg",
	"456_744_roi.jpg",
	"458_185_lbp.jpg",
	"458_185_roi.jpg",
	"458_193_lbp.jpg",
	"458_193_roi.jpg",
	"458_205_lbp.jpg",
	"458_205_roi.jpg",
	"458_232_lbp.jpg",
	"458_232_roi.jpg",
	"458_258_lbp.jpg",
	"458_258_roi.jpg",
	"458_273_lbp.jpg",
	"458_273_roi.jpg",
	"458_301_lbp.jpg",
	"458_301_roi.jpg",
	"458_302_lbp.jpg",
	"458_302_roi.jpg",
	"458_315_lbp.jpg",
	"458_315_roi.jpg",
	"458_317_lbp.jpg",
	"458_317_roi.jpg",
	"458_363_lbp.jpg",
	"458_363_roi.jpg",
	"458_386_lbp.jpg",
	"458_386_roi.jpg",
	"459_137_lbp.jpg",
	"459_137_roi.jpg",
	"459_288_lbp.jpg",
	"459_288_roi.jpg",
	"459_355_lbp.jpg",
	"459_355_roi.jpg",
	"459_358_lbp.jpg",
	"459_358_roi.jpg",
	"459_363_lbp.jpg",
	"459_363_roi.jpg",
	"459_366_lbp.jpg",
	"459_366_roi.jpg",
	"459_370_lbp.jpg",
	"459_370_roi.jpg",
	"459_378_lbp.jpg",
	"459_378_roi.jpg",
	"459_400_lbp.jpg",
	"459_400_roi.jpg",
	"459_428_lbp.jpg",
	"459_428_roi.jpg",
	"459_466_lbp.jpg",
	"459_466_roi.jpg",
	"459_474_lbp.jpg",
	"459_474_roi.jpg",
	"459_561_lbp.jpg",
	"459_561_roi.jpg",
	"459_566_lbp.jpg",
	"459_566_roi.jpg",
	"459_598_lbp.jpg",
	"459_598_roi.jpg",
	"459_601_lbp.jpg",
	"459_601_roi.jpg",
	"460_362_lbp.jpg",
	"460_362_roi.jpg",
	"460_387_lbp.jpg",
	"460_387_roi.jpg",
	"460_415_lbp.jpg",
	"460_415_roi.jpg",
	"460_523_lbp.jpg",
	"460_523_roi.jpg",
	"461_106_lbp.jpg",
	"461_106_roi.jpg",
	"461_109_lbp.jpg",
	"461_109_roi.jpg",
	"461_117_lbp.jpg",
	"461_117_roi.jpg",
	"461_118_lbp.jpg",
	"461_118_roi.jpg",
	"461_137_lbp.jpg",
	"461_137_roi.jpg",
	"461_138_lbp.jpg",
	"461_138_roi.jpg",
	"461_156_lbp.jpg",
	"461_156_roi.jpg",
	"461_31_lbp.jpg",
	"461_31_roi.jpg",
	"461_50_lbp.jpg",
	"461_50_roi.jpg",
	"461_54_lbp.jpg",
	"461_54_roi.jpg",
	"461_59_lbp.jpg",
	"461_59_roi.jpg",
	"462_119_lbp.jpg",
	"462_119_roi.jpg",
	"462_123_lbp.jpg",
	"462_123_roi.jpg",
	"463_609_lbp.jpg",
	"463_609_roi.jpg",
	"463_643_lbp.jpg",
	"463_643_roi.jpg",
	"463_693_lbp.jpg",
	"463_693_roi.jpg",
	"464_851_lbp.jpg",
	"464_851_roi.jpg",
	"464_857_lbp.jpg",
	"464_857_roi.jpg",
	"465_186_lbp.jpg",
	"465_186_roi.jpg",
	"465_192_lbp.jpg",
	"465_192_roi.jpg",
	"469_908_lbp.jpg",
	"469_908_roi.jpg",
	"470_235_lbp.jpg",
	"470_235_roi.jpg",
	"470_950_lbp.jpg",
	"470_950_roi.jpg",
	"471_578_lbp.jpg",
	"471_578_roi.jpg",
	"471_591_lbp.jpg",
	"471_591_roi.jpg",
	"471_614_lbp.jpg",
	"471_614_roi.jpg",
	"478_478_lbp.jpg",
	"478_478_roi.jpg",
	"484_107_lbp.jpg",
	"484_107_roi.jpg",
	"484_113_lbp.jpg",
	"484_113_roi.jpg",
	"484_117_lbp.jpg",
	"484_117_roi.jpg",
	"484_123_lbp.jpg",
	"484_123_roi.jpg",
	"484_125_lbp.jpg",
	"484_125_roi.jpg",
	"484_127_lbp.jpg",
	"484_127_roi.jpg",
	"484_128_lbp.jpg",
	"484_128_roi.jpg",
	"484_132_lbp.jpg",
	"484_132_roi.jpg",
	"484_139_lbp.jpg",
	"484_139_roi.jpg",
	"484_141_lbp.jpg",
	"484_141_roi.jpg",
	"484_142_lbp.jpg",
	"484_142_roi.jpg",
	"484_143_lbp.jpg",
	"484_143_roi.jpg",
	"484_145_lbp.jpg",
	"484_145_roi.jpg",
	"484_148_lbp.jpg",
	"484_148_roi.jpg",
	"484_149_lbp.jpg",
	"484_149_roi.jpg",
	"484_151_lbp.jpg",
	"484_151_roi.jpg",
	"484_155_lbp.jpg",
	"484_155_roi.jpg",
	"484_156_lbp.jpg",
	"484_156_roi.jpg",
	"484_157_lbp.jpg",
	"484_157_roi.jpg",
	"484_159_lbp.jpg",
	"484_159_roi.jpg",
	"484_162_lbp.jpg",
	"484_162_roi.jpg",
	"484_170_lbp.jpg",
	"484_170_roi.jpg",
	"484_171_lbp.jpg",
	"484_171_roi.jpg",
	"484_172_lbp.jpg",
	"484_172_roi.jpg",
	"484_173_lbp.jpg",
	"484_173_roi.jpg",
	"484_178_lbp.jpg",
	"484_178_roi.jpg",
	"484_179_lbp.jpg",
	"484_179_roi.jpg",
	"484_183_lbp.jpg",
	"484_183_roi.jpg",
	"484_184_lbp.jpg",
	"484_184_roi.jpg",
	"484_187_lbp.jpg",
	"484_187_roi.jpg",
	"484_188_lbp.jpg",
	"484_188_roi.jpg",
	"484_189_lbp.jpg",
	"484_189_roi.jpg",
	"484_190_lbp.jpg",
	"484_190_roi.jpg",
	"484_194_lbp.jpg",
	"484_194_roi.jpg",
	"484_35_lbp.jpg",
	"484_35_roi.jpg",
	"484_38_lbp.jpg",
	"484_38_roi.jpg",
	"484_47_lbp.jpg",
	"484_47_roi.jpg",
	"484_57_lbp.jpg",
	"484_57_roi.jpg",
	"484_60_lbp.jpg",
	"484_60_roi.jpg",
	"484_84_lbp.jpg",
	"484_84_roi.jpg",
	"484_98_lbp.jpg",
	"484_98_roi.jpg",
	"485_1357_lbp.jpg",
	"485_1357_roi.jpg",
	"486_1493_lbp.jpg",
	"486_1493_roi.jpg",
	"486_1554_lbp.jpg",
	"486_1554_roi.jpg",
	"494_14_lbp.jpg",
	"494_14_roi.jpg",
	"494_140_lbp.jpg",
	"494_140_roi.jpg",
	"494_156_lbp.jpg",
	"494_156_roi.jpg",
	"494_162_lbp.jpg",
	"494_162_roi.jpg",
	"494_164_lbp.jpg",
	"494_164_roi.jpg",
	"494_179_lbp.jpg",
	"494_179_roi.jpg",
	"494_214_lbp.jpg",
	"494_214_roi.jpg",
	"494_226_lbp.jpg",
	"494_226_roi.jpg",
	"494_227_lbp.jpg",
	"494_227_roi.jpg",
	"494_230_lbp.jpg",
	"494_230_roi.jpg",
	"494_232_lbp.jpg",
	"494_232_roi.jpg",
	"494_238_lbp.jpg",
	"494_238_roi.jpg",
	"494_249_lbp.jpg",
	"494_249_roi.jpg",
	"494_251_lbp.jpg",
	"494_251_roi.jpg",
	"494_254_lbp.jpg",
	"494_254_roi.jpg",
	"494_256_lbp.jpg",
	"494_256_roi.jpg",
	"494_267_lbp.jpg",
	"494_267_roi.jpg",
	"494_268_lbp.jpg",
	"494_268_roi.jpg",
	"494_269_lbp.jpg",
	"494_269_roi.jpg",
	"494_273_lbp.jpg",
	"494_273_roi.jpg",
	"494_276_lbp.jpg",
	"494_276_roi.jpg",
	"494_278_lbp.jpg",
	"494_278_roi.jpg",
	"494_282_lbp.jpg",
	"494_282_roi.jpg",
	"494_283_lbp.jpg",
	"494_283_roi.jpg",
	"494_287_lbp.jpg",
	"494_287_roi.jpg",
	"494_96_lbp.jpg",
	"494_96_roi.jpg",
	"495_119_lbp.jpg",
	"495_119_roi.jpg",
	"495_15_lbp.jpg",
	"495_15_roi.jpg",
	"495_203_lbp.jpg",
	"495_203_roi.jpg",
	"495_39_lbp.jpg",
	"495_39_roi.jpg",
	"495_479_lbp.jpg",
	"495_479_roi.jpg",
	"495_49_lbp.jpg",
	"495_49_roi.jpg",
	"495_618_lbp.jpg",
	"495_618_roi.jpg",
	"495_635_lbp.jpg",
	"495_635_roi.jpg",
	"495_826_lbp.jpg",
	"495_826_roi.jpg",
	"495_84_lbp.jpg",
	"495_84_roi.jpg",
	"495_854_lbp.jpg",
	"495_854_roi.jpg",
	"495_884_lbp.jpg",
	"495_884_roi.jpg",
	"496_167_lbp.jpg",
	"496_167_roi.jpg",
	"496_169_lbp.jpg",
	"496_169_roi.jpg",
	"496_199_lbp.jpg",
	"496_199_roi.jpg",
	"496_36_lbp.jpg",
	"496_36_roi.jpg",
	"498_104_lbp.jpg",
	"498_104_roi.jpg",
	"498_105_lbp.jpg",
	"498_105_roi.jpg",
	"498_109_lbp.jpg",
	"498_109_roi.jpg",
	"498_131_lbp.jpg",
	"498_131_roi.jpg",
	"498_164_lbp.jpg",
	"498_164_roi.jpg",
	"498_174_lbp.jpg",
	"498_174_roi.jpg",
	"498_181_lbp.jpg",
	"498_181_roi.jpg",
	"498_193_lbp.jpg",
	"498_193_roi.jpg",
	"498_197_lbp.jpg",
	"498_197_roi.jpg",
	"498_201_lbp.jpg",
	"498_201_roi.jpg",
	"498_202_lbp.jpg",
	"498_202_roi.jpg",
	"498_203_lbp.jpg",
	"498_203_roi.jpg",
	"498_206_lbp.jpg",
	"498_206_roi.jpg",
	"498_209_lbp.jpg",
	"498_209_roi.jpg",
	"498_210_lbp.jpg",
	"498_210_roi.jpg",
	"498_213_lbp.jpg",
	"498_213_roi.jpg",
	"498_217_lbp.jpg",
	"498_217_roi.jpg",
	"498_219_lbp.jpg",
	"498_219_roi.jpg",
	"498_222_lbp.jpg",
	"498_222_roi.jpg",
	"498_224_lbp.jpg",
	"498_224_roi.jpg",
	"498_225_lbp.jpg",
	"498_225_roi.jpg",
	"498_231_lbp.jpg",
	"498_231_roi.jpg",
	"498_233_lbp.jpg",
	"498_233_roi.jpg",
	"498_238_lbp.jpg",
	"498_238_roi.jpg",
	"498_34_lbp.jpg",
	"498_34_roi.jpg",
	"498_42_lbp.jpg",
	"498_42_roi.jpg",
	"498_55_lbp.jpg",
	"498_55_roi.jpg",
	"498_59_lbp.jpg",
	"498_59_roi.jpg",
	"498_6_lbp.jpg",
	"498_6_roi.jpg",
	"498_62_lbp.jpg",
	"498_62_roi.jpg",
	"498_71_lbp.jpg",
	"498_71_roi.jpg",
	"498_81_lbp.jpg",
	"498_81_roi.jpg",
	"498_82_lbp.jpg",
	"498_82_roi.jpg",
	"498_83_lbp.jpg",
	"498_83_roi.jpg",
	"498_85_lbp.jpg",
	"498_85_roi.jpg",
	"498_91_lbp.jpg",
	"498_91_roi.jpg",
	"498_93_lbp.jpg",
	"498_93_roi.jpg",
	"498_97_lbp.jpg",
	"498_97_roi.jpg",
	"5_54_lbp.jpg",
	"5_54_roi.jpg",
	"500_100_lbp.jpg",
	"500_100_roi.jpg",
	"500_106_lbp.jpg",
	"500_106_roi.jpg",
	"500_108_lbp.jpg",
	"500_108_roi.jpg",
	"500_114_lbp.jpg",
	"500_114_roi.jpg",
	"500_118_lbp.jpg",
	"500_118_roi.jpg",
	"500_122_lbp.jpg",
	"500_122_roi.jpg",
	"500_126_lbp.jpg",
	"500_126_roi.jpg",
	"500_127_lbp.jpg",
	"500_127_roi.jpg",
	"500_128_lbp.jpg",
	"500_128_roi.jpg",
	"500_131_lbp.jpg",
	"500_131_roi.jpg",
	"500_135_lbp.jpg",
	"500_135_roi.jpg",
	"500_139_lbp.jpg",
	"500_139_roi.jpg",
	"500_142_lbp.jpg",
	"500_142_roi.jpg",
	"500_162_lbp.jpg",
	"500_162_roi.jpg",
	"500_164_lbp.jpg",
	"500_164_roi.jpg",
	"500_165_lbp.jpg",
	"500_165_roi.jpg",
	"500_166_lbp.jpg",
	"500_166_roi.jpg",
	"500_177_lbp.jpg",
	"500_177_roi.jpg",
	"500_179_lbp.jpg",
	"500_179_roi.jpg",
	"500_180_lbp.jpg",
	"500_180_roi.jpg",
	"500_26_lbp.jpg",
	"500_26_roi.jpg",
	"500_4_lbp.jpg",
	"500_4_roi.jpg",
	"500_50_lbp.jpg",
	"500_50_roi.jpg",
	"500_6_lbp.jpg",
	"500_6_roi.jpg",
	"500_69_lbp.jpg",
	"500_69_roi.jpg",
	"500_92_lbp.jpg",
	"500_92_roi.jpg",
	"500_94_lbp.jpg",
	"500_94_roi.jpg",
	"500_95_lbp.jpg",
	"500_95_roi.jpg",
	"6_12_lbp.jpg",
	"6_12_roi.jpg",
	"6_31_lbp.jpg",
	"6_31_roi.jpg",
	"6_39_lbp.jpg",
	"6_39_roi.jpg",
	"6_41_lbp.jpg",
	"6_41_roi.jpg",
	"617_113_lbp.jpg",
	"617_113_roi.jpg",
	"617_117_lbp.jpg",
	"617_117_roi.jpg",
	"617_125_lbp.jpg",
	"617_125_roi.jpg",
	"617_128_lbp.jpg",
	"617_128_roi.jpg",
	"617_132_lbp.jpg",
	"617_132_roi.jpg",
	"617_133_lbp.jpg",
	"617_133_roi.jpg",
	"617_135_lbp.jpg",
	"617_135_roi.jpg",
	"617_164_lbp.jpg",
	"617_164_roi.jpg",
	"617_181_lbp.jpg",
	"617_181_roi.jpg",
	"617_194_lbp.jpg",
	"617_194_roi.jpg",
	"617_225_lbp.jpg",
	"617_225_roi.jpg",
	"617_392_lbp.jpg",
	"617_392_roi.jpg",
	"617_427_lbp.jpg",
	"617_427_roi.jpg",
	"617_79_lbp.jpg",
	"617_79_roi.jpg",
	"617_81_lbp.jpg",
	"617_81_roi.jpg",
	"618_10_lbp.jpg",
	"618_10_roi.jpg",
	"618_105_lbp.jpg",
	"618_105_roi.jpg",
	"618_106_lbp.jpg",
	"618_106_roi.jpg",
	"618_11_lbp.jpg",
	"618_11_roi.jpg",
	"618_110_lbp.jpg",
	"618_110_roi.jpg",
	"618_114_lbp.jpg",
	"618_114_roi.jpg",
	"618_117_lbp.jpg",
	"618_117_roi.jpg",
	"618_120_lbp.jpg",
	"618_120_roi.jpg",
	"618_121_lbp.jpg",
	"618_121_roi.jpg",
	"618_122_lbp.jpg",
	"618_122_roi.jpg",
	"618_129_lbp.jpg",
	"618_129_roi.jpg",
	"618_137_lbp.jpg",
	"618_137_roi.jpg",
	"618_138_lbp.jpg",
	"618_138_roi.jpg",
	"618_14_lbp.jpg",
	"618_14_roi.jpg",
	"618_140_lbp.jpg",
	"618_140_roi.jpg",
	"618_145_lbp.jpg",
	"618_145_roi.jpg",
	"618_147_lbp.jpg",
	"618_147_roi.jpg",
	"618_148_lbp.jpg",
	"618_148_roi.jpg",
	"618_149_lbp.jpg",
	"618_149_roi.jpg",
	"618_150_lbp.jpg",
	"618_150_roi.jpg",
	"618_152_lbp.jpg",
	"618_152_roi.jpg",
	"618_159_lbp.jpg",
	"618_159_roi.jpg",
	"618_160_lbp.jpg",
	"618_160_roi.jpg",
	"618_162_lbp.jpg",
	"618_162_roi.jpg",
	"618_165_lbp.jpg",
	"618_165_roi.jpg",
	"618_169_lbp.jpg",
	"618_169_roi.jpg",
	"618_170_lbp.jpg",
	"618_170_roi.jpg",
	"618_176_lbp.jpg",
	"618_176_roi.jpg",
	"618_179_lbp.jpg",
	"618_179_roi.jpg",
	"618_18_lbp.jpg",
	"618_18_roi.jpg",
	"618_180_lbp.jpg",
	"618_180_roi.jpg",
	"618_181_lbp.jpg",
	"618_181_roi.jpg",
	"618_183_lbp.jpg",
	"618_183_roi.jpg",
	"618_188_lbp.jpg",
	"618_188_roi.jpg",
	"618_189_lbp.jpg",
	"618_189_roi.jpg",
	"618_19_lbp.jpg",
	"618_19_roi.jpg",
	"618_190_lbp.jpg",
	"618_190_roi.jpg",
	"618_21_lbp.jpg",
	"618_21_roi.jpg",
	"618_22_lbp.jpg",
	"618_22_roi.jpg",
	"618_23_lbp.jpg",
	"618_23_roi.jpg",
	"618_24_lbp.jpg",
	"618_24_roi.jpg",
	"618_29_lbp.jpg",
	"618_29_roi.jpg",
	"618_31_lbp.jpg",
	"618_31_roi.jpg",
	"618_32_lbp.jpg",
	"618_32_roi.jpg",
	"618_33_lbp.jpg",
	"618_33_roi.jpg",
	"618_34_lbp.jpg",
	"618_34_roi.jpg",
	"618_35_lbp.jpg",
	"618_35_roi.jpg",
	"618_36_lbp.jpg",
	"618_36_roi.jpg",
	"618_39_lbp.jpg",
	"618_39_roi.jpg",
	"618_42_lbp.jpg",
	"618_42_roi.jpg",
	"618_44_lbp.jpg",
	"618_44_roi.jpg",
	"618_45_lbp.jpg",
	"618_45_roi.jpg",
	"618_50_lbp.jpg",
	"618_50_roi.jpg",
	"618_54_lbp.jpg",
	"618_54_roi.jpg",
	"618_61_lbp.jpg",
	"618_61_roi.jpg",
	"618_66_lbp.jpg",
	"618_66_roi.jpg",
	"618_67_lbp.jpg",
	"618_67_roi.jpg",
	"618_7_lbp.jpg",
	"618_7_roi.jpg",
	"618_70_lbp.jpg",
	"618_70_roi.jpg",
	"618_74_lbp.jpg",
	"618_74_roi.jpg",
	"618_77_lbp.jpg",
	"618_77_roi.jpg",
	"618_79_lbp.jpg",
	"618_79_roi.jpg",
	"618_82_lbp.jpg",
	"618_82_roi.jpg",
	"618_89_lbp.jpg",
	"618_89_roi.jpg",
	"618_9_lbp.jpg",
	"618_9_roi.jpg",
	"619_319_lbp.jpg",
	"619_319_roi.jpg",
	"619_424_lbp.jpg",
	"619_424_roi.jpg",
	"619_428_lbp.jpg",
	"619_428_roi.jpg",
	"619_479_lbp.jpg",
	"619_479_roi.jpg",
	"619_480_lbp.jpg",
	"619_480_roi.jpg",
	"619_485_lbp.jpg",
	"619_485_roi.jpg",
	"619_488_lbp.jpg",
	"619_488_roi.jpg",
	"619_490_lbp.jpg",
	"619_490_roi.jpg",
	"619_497_lbp.jpg",
	"619_497_roi.jpg",
	"619_500_lbp.jpg",
	"619_500_roi.jpg",
	"619_501_lbp.jpg",
	"619_501_roi.jpg",
	"620_205_lbp.jpg",
	"620_205_roi.jpg",
	"620_237_lbp.jpg",
	"620_237_roi.jpg",
	"620_304_lbp.jpg",
	"620_304_roi.jpg",
	"620_400_lbp.jpg",
	"620_400_roi.jpg",
	"620_407_lbp.jpg",
	"620_407_roi.jpg",
	"620_409_lbp.jpg",
	"620_409_roi.jpg",
	"620_415_lbp.jpg",
	"620_415_roi.jpg",
	"620_444_lbp.jpg",
	"620_444_roi.jpg",
	"620_469_lbp.jpg",
	"620_469_roi.jpg",
	"620_491_lbp.jpg",
	"620_491_roi.jpg",
	"620_492_lbp.jpg",
	"620_492_roi.jpg",
	"620_493_lbp.jpg",
	"620_493_roi.jpg",
	"620_499_lbp.jpg",
	"620_499_roi.jpg",
	"620_501_lbp.jpg",
	"620_501_roi.jpg",
	"620_502_lbp.jpg",
	"620_502_roi.jpg",
	"620_503_lbp.jpg",
	"620_503_roi.jpg",
	"620_86_lbp.jpg",
	"620_86_roi.jpg",
	"620_87_lbp.jpg",
	"620_87_roi.jpg",
	"621_217_lbp.jpg",
	"621_217_roi.jpg",
	"621_444_lbp.jpg",
	"621_444_roi.jpg",
	"621_468_lbp.jpg",
	"621_468_roi.jpg",
	"621_482_lbp.jpg",
	"621_482_roi.jpg",
	"621_554_lbp.jpg",
	"621_554_roi.jpg",
	"621_559_lbp.jpg",
	"621_559_roi.jpg",
	"621_562_lbp.jpg",
	"621_562_roi.jpg",
	"621_565_lbp.jpg",
	"621_565_roi.jpg",
	"621_568_lbp.jpg",
	"621_568_roi.jpg",
	"621_572_lbp.jpg",
	"621_572_roi.jpg",
	"621_577_lbp.jpg",
	"621_577_roi.jpg",
	"621_582_lbp.jpg",
	"621_582_roi.jpg",
	"621_585_lbp.jpg",
	"621_585_roi.jpg",
	"628_136_lbp.jpg",
	"628_136_roi.jpg",
	"628_149_lbp.jpg",
	"628_149_roi.jpg",
	"628_158_lbp.jpg",
	"628_158_roi.jpg",
	"628_366_lbp.jpg",
	"628_366_roi.jpg",
	"628_386_lbp.jpg",
	"628_386_roi.jpg",
	"628_393_lbp.jpg",
	"628_393_roi.jpg",
	"628_397_lbp.jpg",
	"628_397_roi.jpg",
	"628_426_lbp.jpg",
	"628_426_roi.jpg",
	//"628_443_lbp.jpg",
	//"628_443_roi.jpg",
	"628_455_lbp.jpg",
	"628_455_roi.jpg",
	"628_466_lbp.jpg",
	"628_466_roi.jpg",
	"628_467_lbp.jpg",
	"628_467_roi.jpg",
	"628_481_lbp.jpg",
	"628_481_roi.jpg",
	"628_482_lbp.jpg",
	"628_482_roi.jpg",
	"628_483_lbp.jpg",
	"628_483_roi.jpg",
	"628_487_lbp.jpg",
	"628_487_roi.jpg",
	"628_494_lbp.jpg",
	"628_494_roi.jpg",
	"628_495_lbp.jpg",
	"628_495_roi.jpg",
	"628_497_lbp.jpg",
	"628_497_roi.jpg",
	"628_498_lbp.jpg",
	"628_498_roi.jpg",
	"628_499_lbp.jpg",
	"628_499_roi.jpg",
	"628_502_lbp.jpg",
	"628_502_roi.jpg",
	"628_515_lbp.jpg",
	"628_515_roi.jpg",
	"628_517_lbp.jpg",
	"628_517_roi.jpg",
	"628_525_lbp.jpg",
	"628_525_roi.jpg",
	"628_537_lbp.jpg",
	"628_537_roi.jpg",
	"628_538_lbp.jpg",
	"628_538_roi.jpg",
	"628_545_lbp.jpg",
	"628_545_roi.jpg",
	"628_557_lbp.jpg",
	"628_557_roi.jpg",
	"632_242_lbp.jpg",
	"632_242_roi.jpg",
	"632_248_lbp.jpg",
	"632_248_roi.jpg",
	"632_253_lbp.jpg",
	"632_253_roi.jpg",
	"632_286_lbp.jpg",
	"632_286_roi.jpg",
	"632_321_lbp.jpg",
	"632_321_roi.jpg",
	"632_329_lbp.jpg",
	"632_329_roi.jpg",
	"632_377_lbp.jpg",
	"632_377_roi.jpg",
	"632_380_lbp.jpg",
	"632_380_roi.jpg",
	"632_437_lbp.jpg",
	"632_437_roi.jpg",
	"633_113_lbp.jpg",
	"633_113_roi.jpg",
	"633_118_lbp.jpg",
	"633_118_roi.jpg",
	"633_128_lbp.jpg",
	"633_128_roi.jpg",
	"633_129_lbp.jpg",
	"633_129_roi.jpg",
	"633_134_lbp.jpg",
	"633_134_roi.jpg",
	"633_140_lbp.jpg",
	"633_140_roi.jpg",
	"633_151_lbp.jpg",
	"633_151_roi.jpg",
	"633_152_lbp.jpg",
	"633_152_roi.jpg",
	"633_167_lbp.jpg",
	"633_167_roi.jpg",
	"633_205_lbp.jpg",
	"633_205_roi.jpg",
	"633_215_lbp.jpg",
	"633_215_roi.jpg",
	"633_309_lbp.jpg",
	"633_309_roi.jpg",
	"633_315_lbp.jpg",
	"633_315_roi.jpg",
	"633_321_lbp.jpg",
	"633_321_roi.jpg",
	"633_338_lbp.jpg",
	"633_338_roi.jpg",
	"633_339_lbp.jpg",
	"633_339_roi.jpg",
	"633_341_lbp.jpg",
	"633_341_roi.jpg",
	"634_12_lbp.jpg",
	"634_12_roi.jpg",
	"634_14_lbp.jpg",
	"634_14_roi.jpg",
	"634_179_lbp.jpg",
	"634_179_roi.jpg",
	"634_184_lbp.jpg",
	"634_184_roi.jpg",
	"634_23_lbp.jpg",
	"634_23_roi.jpg",
	"634_318_lbp.jpg",
	"634_318_roi.jpg",
	"634_35_lbp.jpg",
	"634_35_roi.jpg",
	"634_353_lbp.jpg",
	"634_353_roi.jpg",
	"634_389_lbp.jpg",
	"634_389_roi.jpg",
	"634_406_lbp.jpg",
	"634_406_roi.jpg",
	"634_409_lbp.jpg",
	"634_409_roi.jpg",
	"634_411_lbp.jpg",
	"634_411_roi.jpg",
	"634_417_lbp.jpg",
	"634_417_roi.jpg",
	"634_418_lbp.jpg",
	"634_418_roi.jpg",
	"634_420_lbp.jpg",
	"634_420_roi.jpg",
	"634_423_lbp.jpg",
	"634_423_roi.jpg",
	"634_426_lbp.jpg",
	"634_426_roi.jpg",
	"634_427_lbp.jpg",
	"634_427_roi.jpg",
	"634_430_lbp.jpg",
	"634_430_roi.jpg",
	"634_431_lbp.jpg",
	"634_431_roi.jpg",
	"634_434_lbp.jpg",
	"634_434_roi.jpg",
	"634_438_lbp.jpg",
	"634_438_roi.jpg",
	"634_439_lbp.jpg",
	"634_439_roi.jpg",
	"634_461_lbp.jpg",
	"634_461_roi.jpg",
	"634_462_lbp.jpg",
	"634_462_roi.jpg",
	"634_465_lbp.jpg",
	"634_465_roi.jpg",
	"634_468_lbp.jpg",
	"634_468_roi.jpg",
	"634_469_lbp.jpg",
	"634_469_roi.jpg",
	"634_47_lbp.jpg",
	"634_47_roi.jpg",
	"634_472_lbp.jpg",
	"634_472_roi.jpg",
	"634_479_lbp.jpg",
	"634_479_roi.jpg",
	"634_482_lbp.jpg",
	"634_482_roi.jpg",
	"634_486_lbp.jpg",
	"634_486_roi.jpg",
	"634_488_lbp.jpg",
	"634_488_roi.jpg",
	"634_496_lbp.jpg",
	"634_496_roi.jpg",
	"634_502_lbp.jpg",
	"634_502_roi.jpg",
	"634_548_lbp.jpg",
	"634_548_roi.jpg",
	"634_555_lbp.jpg",
	"634_555_roi.jpg",
	"634_557_lbp.jpg",
	"634_557_roi.jpg",
	"634_558_lbp.jpg",
	"634_558_roi.jpg",
	"634_6_lbp.jpg",
	"634_6_roi.jpg",
	"634_66_lbp.jpg",
	"634_66_roi.jpg",
	"634_84_lbp.jpg",
	"634_84_roi.jpg",
	"636_1_lbp.jpg",
	"636_1_roi.jpg",
	"636_100_lbp.jpg",
	"636_100_roi.jpg",
	"636_103_lbp.jpg",
	"636_103_roi.jpg",
	"636_112_lbp.jpg",
	"636_112_roi.jpg",
	"636_13_lbp.jpg",
	"636_13_roi.jpg",
	"636_19_lbp.jpg",
	"636_19_roi.jpg",
	"636_20_lbp.jpg",
	"636_20_roi.jpg",
	"636_26_lbp.jpg",
	"636_26_roi.jpg",
	"636_28_lbp.jpg",
	"636_28_roi.jpg",
	"636_3_lbp.jpg",
	"636_3_roi.jpg",
	"636_34_lbp.jpg",
	"636_34_roi.jpg",
	"636_4_lbp.jpg",
	"636_4_roi.jpg",
	"636_44_lbp.jpg",
	"636_44_roi.jpg",
	"636_48_lbp.jpg",
	"636_48_roi.jpg",
	"636_59_lbp.jpg",
	"636_59_roi.jpg",
	"636_60_lbp.jpg",
	"636_60_roi.jpg",
	"636_65_lbp.jpg",
	"636_65_roi.jpg",
	"636_71_lbp.jpg",
	"636_71_roi.jpg",
	"636_72_lbp.jpg",
	"636_72_roi.jpg",
	"636_76_lbp.jpg",
	"636_76_roi.jpg",
	"636_94_lbp.jpg",
	"636_94_roi.jpg",
	"7_116_lbp.jpg",
	"7_116_roi.jpg"
};
String otherFileName[502] = {
	"473_491_lbp.jpg",
	"473_491_roi.jpg",
	"473_495_lbp.jpg",
	"473_495_roi.jpg",
	"473_496_lbp.jpg",
	"473_496_roi.jpg",
	"473_514_lbp.jpg",
	"473_514_roi.jpg",
	"473_534_lbp.jpg",
	"473_534_roi.jpg",
	"473_582_lbp.jpg",
	"473_582_roi.jpg",
	"473_583_lbp.jpg",
	"473_583_roi.jpg",
	"474_1000_lbp.jpg",
	"474_1000_roi.jpg",
	"474_1001_lbp.jpg",
	"474_1001_roi.jpg",
	"474_1008_lbp.jpg",
	"474_1008_roi.jpg",
	"474_1010_lbp.jpg",
	"474_1010_roi.jpg",
	"474_1033_lbp.jpg",
	"474_1033_roi.jpg",
	"474_1041_lbp.jpg",
	"474_1041_roi.jpg",
	"474_1044_lbp.jpg",
	"474_1044_roi.jpg",
	"474_1047_lbp.jpg",
	"474_1047_roi.jpg",
	"474_1056_lbp.jpg",
	"474_1056_roi.jpg",
	"474_1058_lbp.jpg",
	"474_1058_roi.jpg",
	"474_1060_lbp.jpg",
	"474_1060_roi.jpg",
	"474_1074_lbp.jpg",
	"474_1074_roi.jpg",
	"474_1075_lbp.jpg",
	"474_1075_roi.jpg",
	"474_1086_lbp.jpg",
	"474_1086_roi.jpg",
	"474_1093_lbp.jpg",
	"474_1093_roi.jpg",
	"474_1099_lbp.jpg",
	"474_1099_roi.jpg",
	"474_1100_lbp.jpg",
	"474_1100_roi.jpg",
	"474_1102_lbp.jpg",
	"474_1102_roi.jpg",
	"474_1104_lbp.jpg",
	"474_1104_roi.jpg",
	"474_112_lbp.jpg",
	"474_112_roi.jpg",
	"474_13_lbp.jpg",
	"474_13_roi.jpg",
	"474_136_lbp.jpg",
	"474_136_roi.jpg",
	"474_174_lbp.jpg",
	"474_174_roi.jpg",
	"474_222_lbp.jpg",
	"474_222_roi.jpg",
	"474_255_lbp.jpg",
	"474_255_roi.jpg",
	"474_274_lbp.jpg",
	"474_274_roi.jpg",
	"474_345_lbp.jpg",
	"474_345_roi.jpg",
	"474_361_lbp.jpg",
	"474_361_roi.jpg",
	"474_41_lbp.jpg",
	"474_41_roi.jpg",
	"474_448_lbp.jpg",
	"474_448_roi.jpg",
	"474_49_lbp.jpg",
	"474_49_roi.jpg",
	"474_61_lbp.jpg",
	"474_61_roi.jpg",
	"474_616_lbp.jpg",
	"474_616_roi.jpg",
	"474_66_lbp.jpg",
	"474_66_roi.jpg",
	"474_735_lbp.jpg",
	"474_735_roi.jpg",
	"474_740_lbp.jpg",
	"474_740_roi.jpg",
	"474_768_lbp.jpg",
	"474_768_roi.jpg",
	"474_804_lbp.jpg",
	"474_804_roi.jpg",
	"474_839_lbp.jpg",
	"474_839_roi.jpg",
	"474_863_lbp.jpg",
	"474_863_roi.jpg",
	"474_87_lbp.jpg",
	"474_87_roi.jpg",
	"474_881_lbp.jpg",
	"474_881_roi.jpg",
	"474_882_lbp.jpg",
	"474_882_roi.jpg",
	"474_89_lbp.jpg",
	"474_89_roi.jpg",
	"474_897_lbp.jpg",
	"474_897_roi.jpg",
	"474_906_lbp.jpg",
	"474_906_roi.jpg",
	"474_912_lbp.jpg",
	"474_912_roi.jpg",
	"474_913_lbp.jpg",
	"474_913_roi.jpg",
	"474_919_lbp.jpg",
	"474_919_roi.jpg",
	"474_922_lbp.jpg",
	"474_922_roi.jpg",
	"474_936_lbp.jpg",
	"474_936_roi.jpg",
	"474_938_lbp.jpg",
	"474_938_roi.jpg",
	"474_946_lbp.jpg",
	"474_946_roi.jpg",
	"474_949_lbp.jpg",
	"474_949_roi.jpg",
	"474_951_lbp.jpg",
	"474_951_roi.jpg",
	"474_965_lbp.jpg",
	"474_965_roi.jpg",
	"474_969_lbp.jpg",
	"474_969_roi.jpg",
	"474_976_lbp.jpg",
	"474_976_roi.jpg",
	"474_977_lbp.jpg",
	"474_977_roi.jpg",
	"474_978_lbp.jpg",
	"474_978_roi.jpg",
	"474_983_lbp.jpg",
	"474_983_roi.jpg",
	"474_985_lbp.jpg",
	"474_985_roi.jpg",
	"474_986_lbp.jpg",
	"474_986_roi.jpg",
	"475_108_lbp.jpg",
	"475_108_roi.jpg",
	"475_157_lbp.jpg",
	"475_157_roi.jpg",
	"475_161_lbp.jpg",
	"475_161_roi.jpg",
	"475_223_lbp.jpg",
	"475_223_roi.jpg",
	"475_264_lbp.jpg",
	"475_264_roi.jpg",
	"475_620_lbp.jpg",
	"475_620_roi.jpg",
	"475_87_lbp.jpg",
	"475_87_roi.jpg",
	"476_1408_lbp.jpg",
	"476_1408_roi.jpg",
	"476_142_lbp.jpg",
	"476_142_roi.jpg",
	"476_1512_lbp.jpg",
	"476_1512_roi.jpg",
	"476_1529_lbp.jpg",
	"476_1529_roi.jpg",
	"476_1533_lbp.jpg",
	"476_1533_roi.jpg",
	"476_212_lbp.jpg",
	"476_212_roi.jpg",
	"476_244_lbp.jpg",
	"476_244_roi.jpg",
	"476_263_lbp.jpg",
	"476_263_roi.jpg",
	"476_336_lbp.jpg",
	"476_336_roi.jpg",
	"476_378_lbp.jpg",
	"476_378_roi.jpg",
	"476_505_lbp.jpg",
	"476_505_roi.jpg",
	"476_556_lbp.jpg",
	"476_556_roi.jpg",
	"476_628_lbp.jpg",
	"476_628_roi.jpg",
	"477_2269_lbp.jpg",
	"477_2269_roi.jpg",
	"477_2293_lbp.jpg",
	"477_2293_roi.jpg",
	"477_2303_lbp.jpg",
	"477_2303_roi.jpg",
	"477_2312_lbp.jpg",
	"477_2312_roi.jpg",
	"477_2319_lbp.jpg",
	"477_2319_roi.jpg",
	"477_2325_lbp.jpg",
	"477_2325_roi.jpg",
	"477_2331_lbp.jpg",
	"477_2331_roi.jpg",
	"477_2333_lbp.jpg",
	"477_2333_roi.jpg",
	"477_2362_lbp.jpg",
	"477_2362_roi.jpg",
	"477_2419_lbp.jpg",
	"477_2419_roi.jpg",
	"477_2443_lbp.jpg",
	"477_2443_roi.jpg",
	"477_2444_lbp.jpg",
	"477_2444_roi.jpg",
	"477_2449_lbp.jpg",
	"477_2449_roi.jpg",
	"478_184_lbp.jpg",
	"478_184_roi.jpg",
	"478_398_lbp.jpg",
	"478_398_roi.jpg",
	"478_437_lbp.jpg",
	"478_437_roi.jpg",
	"478_478_lbp.jpg",
	"478_478_roi.jpg",
	"478_694_lbp.jpg",
	"478_694_roi.jpg",
	"478_699_lbp.jpg",
	"478_699_roi.jpg",
	"479_104_lbp.jpg",
	"479_104_roi.jpg",
	"479_114_lbp.jpg",
	"479_114_roi.jpg",
	"479_123_lbp.jpg",
	"479_123_roi.jpg",
	"479_132_lbp.jpg",
	"479_132_roi.jpg",
	"479_146_lbp.jpg",
	"479_146_roi.jpg",
	"479_149_lbp.jpg",
	"479_149_roi.jpg",
	"479_162_lbp.jpg",
	"479_162_roi.jpg",
	"479_20_lbp.jpg",
	"479_20_roi.jpg",
	"479_201_lbp.jpg",
	"479_201_roi.jpg",
	"479_203_lbp.jpg",
	"479_203_roi.jpg",
	"479_236_lbp.jpg",
	"479_236_roi.jpg",
	"479_270_lbp.jpg",
	"479_270_roi.jpg",
	"479_73_lbp.jpg",
	"479_73_roi.jpg",
	"479_78_lbp.jpg",
	"479_78_roi.jpg",
	"480_271_lbp.jpg",
	"480_271_roi.jpg",
	"480_377_lbp.jpg",
	"480_377_roi.jpg",
	"480_418_lbp.jpg",
	"480_418_roi.jpg",
	"480_503_lbp.jpg",
	"480_503_roi.jpg",
	"480_537_lbp.jpg",
	"480_537_roi.jpg",
	"480_578_lbp.jpg",
	"480_578_roi.jpg",
	"480_616_lbp.jpg",
	"480_616_roi.jpg",
	"480_638_lbp.jpg",
	"480_638_roi.jpg",
	"480_700_lbp.jpg",
	"480_700_roi.jpg",
	"480_755_lbp.jpg",
	"480_755_roi.jpg",
	"481_103_lbp.jpg",
	"481_103_roi.jpg",
	"481_106_lbp.jpg",
	"481_106_roi.jpg",
	"481_108_lbp.jpg",
	"481_108_roi.jpg",
	"481_117_lbp.jpg",
	"481_117_roi.jpg",
	"481_122_lbp.jpg",
	"481_122_roi.jpg",
	"481_137_lbp.jpg",
	"481_137_roi.jpg",
	"481_175_lbp.jpg",
	"481_175_roi.jpg",
	"481_177_lbp.jpg",
	"481_177_roi.jpg",
	"481_185_lbp.jpg",
	"481_185_roi.jpg",
	"481_191_lbp.jpg",
	"481_191_roi.jpg",
	"481_204_lbp.jpg",
	"481_204_roi.jpg",
	"481_210_lbp.jpg",
	"481_210_roi.jpg",
	"481_22_lbp.jpg",
	"481_22_roi.jpg",
	"481_220_lbp.jpg",
	"481_220_roi.jpg",
	"481_221_lbp.jpg",
	"481_221_roi.jpg",
	"481_222_lbp.jpg",
	"481_222_roi.jpg",
	"481_38_lbp.jpg",
	"481_38_roi.jpg",
	"481_39_lbp.jpg",
	"481_39_roi.jpg",
	"481_40_lbp.jpg",
	"481_40_roi.jpg",
	"481_44_lbp.jpg",
	"481_44_roi.jpg",
	"481_53_lbp.jpg",
	"481_53_roi.jpg",
	"481_54_lbp.jpg",
	"481_54_roi.jpg",
	"481_63_lbp.jpg",
	"481_63_roi.jpg",
	"481_69_lbp.jpg",
	"481_69_roi.jpg",
	"481_71_lbp.jpg",
	"481_71_roi.jpg",
	"481_73_lbp.jpg",
	"481_73_roi.jpg",
	"481_88_lbp.jpg",
	"481_88_roi.jpg",
	"481_95_lbp.jpg",
	"481_95_roi.jpg",
	"481_96_lbp.jpg",
	"481_96_roi.jpg",
	"482_1018_lbp.jpg",
	"482_1018_roi.jpg",
	"482_1050_lbp.jpg",
	"482_1050_roi.jpg",
	"482_1063_lbp.jpg",
	"482_1063_roi.jpg",
	"482_1083_lbp.jpg",
	"482_1083_roi.jpg",
	"482_1113_lbp.jpg",
	"482_1113_roi.jpg",
	"482_1118_lbp.jpg",
	"482_1118_roi.jpg",
	"482_1120_lbp.jpg",
	"482_1120_roi.jpg",
	"482_1121_lbp.jpg",
	"482_1121_roi.jpg",
	"482_1122_lbp.jpg",
	"482_1122_roi.jpg",
	"482_1125_lbp.jpg",
	"482_1125_roi.jpg",
	"482_1144_lbp.jpg",
	"482_1144_roi.jpg",
	"482_1150_lbp.jpg",
	"482_1150_roi.jpg",
	"482_1170_lbp.jpg",
	"482_1170_roi.jpg",
	"482_1237_lbp.jpg",
	"482_1237_roi.jpg",
	"482_1248_lbp.jpg",
	"482_1248_roi.jpg",
	"482_1265_lbp.jpg",
	"482_1265_roi.jpg",
	"482_1368_lbp.jpg",
	"482_1368_roi.jpg",
	"482_1370_lbp.jpg",
	"482_1370_roi.jpg",
	"482_1390_lbp.jpg",
	"482_1390_roi.jpg",
	"482_141_lbp.jpg",
	"482_141_roi.jpg",
	"482_151_lbp.jpg",
	"482_151_roi.jpg",
	"482_181_lbp.jpg",
	"482_181_roi.jpg",
	"482_191_lbp.jpg",
	"482_191_roi.jpg",
	"482_212_lbp.jpg",
	"482_212_roi.jpg",
	"482_214_lbp.jpg",
	"482_214_roi.jpg",
	"482_217_lbp.jpg",
	"482_217_roi.jpg",
	"482_218_lbp.jpg",
	"482_218_roi.jpg",
	"482_221_lbp.jpg",
	"482_221_roi.jpg",
	"482_224_lbp.jpg",
	"482_224_roi.jpg",
	"482_249_lbp.jpg",
	"482_249_roi.jpg",
	"482_254_lbp.jpg",
	"482_254_roi.jpg",
	"482_262_lbp.jpg",
	"482_262_roi.jpg",
	"482_282_lbp.jpg",
	"482_282_roi.jpg",
	"482_285_lbp.jpg",
	"482_285_roi.jpg",
	"482_289_lbp.jpg",
	"482_289_roi.jpg",
	"482_294_lbp.jpg",
	"482_294_roi.jpg",
	"482_301_lbp.jpg",
	"482_301_roi.jpg",
	"482_313_lbp.jpg",
	"482_313_roi.jpg",
	"482_332_lbp.jpg",
	"482_332_roi.jpg",
	"482_335_lbp.jpg",
	"482_335_roi.jpg",
	"482_970_lbp.jpg",
	"482_970_roi.jpg",
	"482_988_lbp.jpg",
	"482_988_roi.jpg",
	"483_124_lbp.jpg",
	"483_124_roi.jpg",
	"483_221_lbp.jpg",
	"483_221_roi.jpg",
	"483_237_lbp.jpg",
	"483_237_roi.jpg",
	"483_259_lbp.jpg",
	"483_259_roi.jpg",
	"483_275_lbp.jpg",
	"483_275_roi.jpg",
	"483_290_lbp.jpg",
	"483_290_roi.jpg",
	"483_335_lbp.jpg",
	"483_335_roi.jpg",
	"483_366_lbp.jpg",
	"483_366_roi.jpg",
	"483_504_lbp.jpg",
	"483_504_roi.jpg",
	"483_546_lbp.jpg",
	"483_546_roi.jpg",
	"483_569_lbp.jpg",
	"483_569_roi.jpg",
	"483_580_lbp.jpg",
	"483_580_roi.jpg",
	"483_600_lbp.jpg",
	"483_600_roi.jpg",
	"483_603_lbp.jpg",
	"483_603_roi.jpg",
	"483_648_lbp.jpg",
	"483_648_roi.jpg",
	"483_74_lbp.jpg",
	"483_74_roi.jpg",
	"483_99_lbp.jpg",
	"483_99_roi.jpg",
	"638_151_lbp.jpg",
	"638_151_roi.jpg",
	"638_175_lbp.jpg",
	"638_175_roi.jpg",
	"638_193_lbp.jpg",
	"638_193_roi.jpg",
	"638_228_lbp.jpg",
	"638_228_roi.jpg",
	"638_231_lbp.jpg",
	"638_231_roi.jpg",
	"638_27_lbp.jpg",
	"638_27_roi.jpg",
	"638_291_lbp.jpg",
	"638_291_roi.jpg",
	"638_299_lbp.jpg",
	"638_299_roi.jpg",
	"638_307_lbp.jpg",
	"638_307_roi.jpg",
	"638_314_lbp.jpg",
	"638_314_roi.jpg",
	"638_318_lbp.jpg",
	"638_318_roi.jpg",
	"638_362_lbp.jpg",
	"638_362_roi.jpg",
	"638_363_lbp.jpg",
	"638_363_roi.jpg",
	"638_55_lbp.jpg",
	"638_55_roi.jpg",
	"638_95_lbp.jpg",
	"638_95_roi.jpg",
	"675_106_lbp.jpg",
	"675_106_roi.jpg",
	"675_108_lbp.jpg",
	"675_108_roi.jpg",
	"675_111_lbp.jpg",
	"675_111_roi.jpg",
	"676_291_lbp.jpg",
	"676_291_roi.jpg",
	"676_521_lbp.jpg",
	"676_521_roi.jpg",
	"676_755_lbp.jpg",
	"676_755_roi.jpg",
	"676_76_lbp.jpg",
	"676_76_roi.jpg",
	"677_336_lbp.jpg",
	"677_336_roi.jpg",
	"677_723_lbp.jpg",
	"677_723_roi.jpg",
	"677_835_lbp.jpg",
	"677_835_roi.jpg",
	"685_536_lbp.jpg",
	"685_536_roi.jpg",
	"685_556_lbp.jpg",
	"685_556_roi.jpg",
	"685_583_lbp.jpg",
	"685_583_roi.jpg",
	"685_589_lbp.jpg",
	"685_589_roi.jpg",
	"685_598_lbp.jpg",
	"685_598_roi.jpg"
};
int main()
{
	file.open(record + "histogram.txt", ios::out);      //開啟檔案
	if (!file) {     //檢查檔案是否成功開啟
		cerr << "Can't open file!\n";
		exit(1);     //在不正常情形下，中斷程式的執行
	}
	Mat lbp, roi;
	int hcount[256] = { 0 };
	for (int i = 0; i<cloudAmount * 2; i += 2) {
		//file << cloudFileName[i] << "\n";
		cout << cloudFileName[i] << endl;
		lbp = imread(loadLocation + cloudFileName[i], 0);
		roi = imread(loadLocation + cloudFileName[i + 1]);
		//imshow("lbp", lbp);
		//imshow("roi", roi);
		int rows = lbp.rows;
		int cols = lbp.cols;
		int pixelCount = 0;
		for (int g = 0; g < 256; g++)
			hcount[g] = 0;
		for (int r = 0; r < rows; ++r) {
			const uchar *lbpdata = lbp.ptr<uchar>(r);
			const uchar *roidata = roi.ptr<uchar>(r);
			for (int c = 0; c < cols; ++c)
			{
				if (!(roidata[3 * c] == 255 && roidata[3 * c + 1] == 0 && roidata[3 * c + 2] == 255)) {
					hcount[lbpdata[c]]++;
					pixelCount++;
				}
				else {
					//cout << "MAGENTA" << endl;
				}
			}
		}
		lbp.release();
		roi.release();
		for (int z = 0; z<256 && pixelCount != 0; z++) {
			cout << "z = " << z << " hcount = ";
			cout << hcount[z];
			histogram[i][z] = (float)hcount[z] / pixelCount;
			//file << histogram[i][z] << ",\n";
			cout << " hist = " << histogram[i][z] << " pixel = " << pixelCount << endl;
		}
		//file << "\n";
		cout << "Have " << pixelCount << "pixels." << endl;
	}
	for (int i = 0; i<otherAmount * 2; i += 2) {
		//file << otherFileName[i] << "\n";
		cout << otherFileName[i] << endl;
		lbp = imread(loadLocation2 + otherFileName[i], 0);
		roi = imread(loadLocation2 + otherFileName[i + 1]);
		//imshow("lbp", lbp);
		//imshow("roi", roi);
		int rows = lbp.rows;
		int cols = lbp.cols;
		int pixelCount = 0;
		for (int g = 0; g < 256; g++)
			hcount[g] = 0;
		for (int r = 0; r < rows; ++r) {
			const uchar *lbpdata = lbp.ptr<uchar>(r);
			const uchar *roidata = roi.ptr<uchar>(r);
			for (int c = 0; c < cols; ++c)
			{
				if (!(roidata[3 * c] == 255 && roidata[3 * c + 1] == 0 && roidata[3 * c + 2] == 255)) {
					hcount[lbpdata[c]]++;
					pixelCount++;
				}
				else {
					//cout << "MAGENTA" << endl;
				}
			}
		}
		lbp.release();
		roi.release();
		for (int z = 0; z<256 && pixelCount != 0; z++) {
			cout << hcount[z] << ",\n";
			histogram[i + cloudAmount][z] = (float)hcount[z] / pixelCount;
			//file << histogram[i + 498][z] << ",\n";
		}
		//file << "\n";
		cout << "Have " << pixelCount << "pixels." << endl;
	}

	for (int i = 0; i<cloudAmount+otherAmount; i++) {
		if (i<cloudAmount)
			tag[i] = 1;
		else
			tag[i] = -1;
	}

	const int num_data = cloudAmount + otherAmount; //資料數
	const int num_column = 256; //欄位數

	Mat trainingDataMat(num_data, num_column, CV_32FC1, histogram);
	Mat labelsMat(num_data, 1, CV_32SC1, tag);

	/* Set up SVM's parameters
	SVM::Params params;
	params.svmType = SVM::C_SVC;
	params.kernelType = SVM::LINEAR;
	params.termCrit = TermCriteria(TermCriteria::MAX_ITER, 100, 1e-6);

	// Train the SVM
	Ptr<SVM> svm = StatModel::train<SVM>(trainingDataMat, ROW_SAMPLE, labelsMat, params);
	svm->save(record + "SVMresult.xml");

	//opencv2版本
	/*CvSVMParams params; //設定 SVM 參數用的物件
	//以下設定 SVM 參數
	params.svm_type = CvSVM::C_SVC;
	params.kernel_type = CvSVM::RBF; //Kernel Function 推薦使用 RBF
	params.gamma = 3;
	params.C = 100;

	const int num_data = cloudAmount+otherAmount; //資料數
	const int num_column = 256; //欄位數

	Mat trainingData(num_data,num_column,CV_32FC1); //訓練陣列
	Mat labels(num_data,1,CV_32FC1); //標籤

	//將資料和 label 分別塞入資料結構中
	for(int n=0; n<num_data; n++){
	for(int c=0; c<num_column; c++){
	training_mat.at<float>(n,c) = histogram[n][c];
	}
	}
	for(int ii=0; ii<num_data; ii++){
	labels.at<float>(ii) = tag[ii];
	}

	//將以上資料結構塞給 SVM Train 做訓練
	CvSVM svm;
	svm.train(training_mat, labels, Mat(), Mat(), params);

	svm.save(record+"svm.sav"); //將訓練好的結果存檔
	/*svm.load(record+"svm.sav"); //將訓練好的存檔讀回來給 svm 物件


	//設定一筆測試資料看看
	Mat img_mat_1d(1,2,CV_32FC1);

	img_mat_1d.at<float>( 0 , 0 ) = 50;
	img_mat_1d.at<float>( 0 , 1 ) = 100;

	//利用 svm 物件
	printf( "%f\n ", svm.predict( img_mat_1d )); //因為 50<100 ，所以會輸出 -1

	img_mat_1d.at<float>( 0 , 0 ) = 99;
	img_mat_1d.at<float>( 0 , 1 ) = 30;
	printf( "%f\n ", svm.predict( img_mat_1d )); //因為 99>30 ，所以會輸出 1
	*/
	system("pause");
	return 0;
}