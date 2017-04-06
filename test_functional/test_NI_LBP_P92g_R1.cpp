/*  =========================================================================
        Author: Leonardo Citraro
        Company:
        Filename: test_functional.cpp
        Last modifed:   06.04.2017 by Leonardo Citraro
        Description:    Functional test
    
        =========================================================================
    
        =========================================================================
    */
    #include "ext3DLBP.hpp"
    #include <iostream>
    #include <string>
    #include <array>
    #include <cassert>
    
    using namespace ext3DLBP;
    
    template<typename T, size_t N>
    bool check(const std::string& test, const Array1D<T,N>& output, const Array1D<T,N>& truth) {
        if( output==truth ) {
            std::cout << test << " passed!\n";
            return true;
        } else {
            std::cout << test << " failed!\n";
            std::cout << "output: [";
            for(const auto& e:output)
                std::cout << e << ",";
            std::cout << "]\n";
            std::cout << "truth:  [";
            for(const auto& e:truth)
                std::cout << e << ",";
            std::cout << "]\n";
            return false;
        }
    }
    template<typename T>
    bool check(const std::string& test, const T output, const T truth) {
        if( output==truth ) {
            std::cout << test << " passed!\n";
            return true;
        } else {
            std::cout << test << " failed!\n";
            std::cout << "output: " << output << "\n";
            std::cout << "truth:  " << truth << "\n";
            return false;
        }
    }  
    
    int main(int argc, char* argv[]){
     
    
std::cout << "=============================================\n";
std::string test = "NI_LBP_P92g_R1";
{
	Array3D<int,3,3,3> array = {{
		{{{165,226,124},{215,96,200},{138,102,175}}},
		{{{59,241,247},{27,52,111},{209,123,210}}},
		{{{147,113,7},{18,118,196},{253,90,98}}}
	}};
	double mur = 44;
	int V = 3;
	NI_LBP<P92g,R1> lbp(mur, V);
	int LBPcode = lbp.convert(array);
	int truth = 49;
	assert( check(test+" Test 0", LBPcode, truth) );
}
{
	Array3D<int,3,3,3> array = {{
		{{{166,24,223},{181,107,131},{96,211,174}}},
		{{{141,13,10},{13,101,180},{195,58,205}}},
		{{{141,169,41},{147,220,80},{221,22,78}}}
	}};
	double mur = 16;
	int V = 3;
	NI_LBP<P92g,R1> lbp(mur, V);
	int LBPcode = lbp.convert(array);
	int truth = 51;
	assert( check(test+" Test 1", LBPcode, truth) );
}
{
	Array3D<int,3,3,3> array = {{
		{{{142,202,136},{144,47,49},{207,217,98}}},
		{{{180,116,10},{71,26,32},{196,131,3}}},
		{{{93,169,92},{155,111,216},{236,237,249}}}
	}};
	double mur = 143;
	int V = 3;
	NI_LBP<P92g,R1> lbp(mur, V);
	int LBPcode = lbp.convert(array);
	int truth = 55;
	assert( check(test+" Test 2", LBPcode, truth) );
}
{
	Array3D<int,3,3,3> array = {{
		{{{86,136,146},{163,208,115},{21,186,71}}},
		{{{152,164,68},{247,237,109},{90,6,28}}},
		{{{28,39,229},{220,58,18},{115,154,79}}}
	}};
	double mur = 113;
	int V = 4;
	NI_LBP<P92g,R1> lbp(mur, V);
	int LBPcode = lbp.convert(array);
	int truth = 47;
	assert( check(test+" Test 3", LBPcode, truth) );
}
{
	Array3D<int,3,3,3> array = {{
		{{{171,253,192},{8,121,139},{148,130,53}}},
		{{{2,203,123},{188,180,248},{209,6,64}}},
		{{{27,56,125},{29,162,117},{210,187,217}}}
	}};
	double mur = 238;
	int V = 3;
	NI_LBP<P92g,R1> lbp(mur, V);
	int LBPcode = lbp.convert(array);
	int truth = 49;
	assert( check(test+" Test 4", LBPcode, truth) );
}
{
	Array3D<int,3,3,3> array = {{
		{{{137,174,60},{121,80,16},{185,118,126}}},
		{{{22,239,140},{195,218,249},{43,146,145}}},
		{{{84,180,60},{58,200,55},{8,159,54}}}
	}};
	double mur = 207;
	int V = 4;
	NI_LBP<P92g,R1> lbp(mur, V);
	int LBPcode = lbp.convert(array);
	int truth = 42;
	assert( check(test+" Test 5", LBPcode, truth) );
}
{
	Array3D<int,3,3,3> array = {{
		{{{40,238,234},{84,84,190},{111,0,86}}},
		{{{80,237,70},{126,146,233},{102,41,216}}},
		{{{67,188,109},{212,31,219},{107,136,122}}}
	}};
	double mur = 86;
	int V = 3;
	NI_LBP<P92g,R1> lbp(mur, V);
	int LBPcode = lbp.convert(array);
	int truth = 45;
	assert( check(test+" Test 6", LBPcode, truth) );
}
{
	Array3D<int,3,3,3> array = {{
		{{{197,138,129},{101,4,12},{132,94,122}}},
		{{{65,64,122},{139,165,250},{108,116,14}}},
		{{{247,187,23},{0,126,64},{170,226,33}}}
	}};
	double mur = 163;
	int V = 3;
	NI_LBP<P92g,R1> lbp(mur, V);
	int LBPcode = lbp.convert(array);
	int truth = 49;
	assert( check(test+" Test 7", LBPcode, truth) );
}
{
	Array3D<int,3,3,3> array = {{
		{{{121,54,117},{229,12,164},{16,47,223}}},
		{{{171,44,192},{114,204,88},{41,48,223}}},
		{{{46,85,189},{221,253,80},{217,110,243}}}
	}};
	double mur = 45;
	int V = 3;
	NI_LBP<P92g,R1> lbp(mur, V);
	int LBPcode = lbp.convert(array);
	int truth = 52;
	assert( check(test+" Test 8", LBPcode, truth) );
}
{
	Array3D<int,3,3,3> array = {{
		{{{178,90,139},{130,122,17},{118,246,28}}},
		{{{184,227,212},{206,157,229},{82,151,129}}},
		{{{82,117,69},{71,192,149},{63,20,216}}}
	}};
	double mur = 225;
	int V = 3;
	NI_LBP<P92g,R1> lbp(mur, V);
	int LBPcode = lbp.convert(array);
	int truth = 47;
	assert( check(test+" Test 9", LBPcode, truth) );
}
{
	Array3D<int,3,3,3> array = {{
		{{{15,157,40},{27,71,30},{112,132,58}}},
		{{{236,254,165},{195,1,87},{219,57,171}}},
		{{{196,216,236},{158,249,212},{18,0,59}}}
	}};
	double mur = 239;
	int V = 4;
	NI_LBP<P92g,R1> lbp(mur, V);
	int LBPcode = lbp.convert(array);
	int truth = 43;
	assert( check(test+" Test 10", LBPcode, truth) );
}
{
	Array3D<int,3,3,3> array = {{
		{{{36,8,20},{181,116,161},{241,204,109}}},
		{{{27,81,85},{91,6,181},{134,223,193}}},
		{{{63,217,88},{48,193,136},{137,147,222}}}
	}};
	double mur = 191;
	int V = 4;
	NI_LBP<P92g,R1> lbp(mur, V);
	int LBPcode = lbp.convert(array);
	int truth = 52;
	assert( check(test+" Test 11", LBPcode, truth) );
}
{
	Array3D<int,3,3,3> array = {{
		{{{149,2,82},{121,106,98},{202,43,59}}},
		{{{88,251,56},{120,51,254},{136,243,198}}},
		{{{8,33,186},{201,59,38},{158,55,42}}}
	}};
	double mur = 206;
	int V = 4;
	NI_LBP<P92g,R1> lbp(mur, V);
	int LBPcode = lbp.convert(array);
	int truth = 41;
	assert( check(test+" Test 12", LBPcode, truth) );
}
{
	Array3D<int,3,3,3> array = {{
		{{{76,112,33},{234,45,161},{231,129,32}}},
		{{{4,204,60},{78,50,114},{88,32,0}}},
		{{{192,60,133},{126,138,41},{131,11,59}}}
	}};
	double mur = 31;
	int V = 3;
	NI_LBP<P92g,R1> lbp(mur, V);
	int LBPcode = lbp.convert(array);
	int truth = 53;
	assert( check(test+" Test 13", LBPcode, truth) );
}
{
	Array3D<int,3,3,3> array = {{
		{{{156,92,128},{209,53,253},{113,243,65}}},
		{{{134,31,240},{89,176,177},{66,150,18}}},
		{{{251,196,96},{31,101,26},{182,82,87}}}
	}};
	double mur = 193;
	int V = 3;
	NI_LBP<P92g,R1> lbp(mur, V);
	int LBPcode = lbp.convert(array);
	int truth = 46;
	assert( check(test+" Test 14", LBPcode, truth) );
}
{
	Array3D<int,3,3,3> array = {{
		{{{180,115,232},{9,237,166},{48,122,203}}},
		{{{32,119,85},{148,117,13},{182,230,164}}},
		{{{75,117,130},{68,218,199},{15,41,205}}}
	}};
	double mur = 251;
	int V = 4;
	NI_LBP<P92g,R1> lbp(mur, V);
	int LBPcode = lbp.convert(array);
	int truth = 44;
	assert( check(test+" Test 15", LBPcode, truth) );
}
{
	Array3D<int,3,3,3> array = {{
		{{{45,225,29},{33,163,111},{73,131,251}}},
		{{{205,49,178},{175,84,241},{148,80,214}}},
		{{{143,118,178},{234,155,73},{11,51,205}}}
	}};
	double mur = 25;
	int V = 3;
	NI_LBP<P92g,R1> lbp(mur, V);
	int LBPcode = lbp.convert(array);
	int truth = 45;
	assert( check(test+" Test 16", LBPcode, truth) );
}
{
	Array3D<int,3,3,3> array = {{
		{{{117,77,245},{87,158,223},{184,236,241}}},
		{{{87,52,76},{80,137,117},{174,28,73}}},
		{{{142,192,85},{32,123,15},{67,42,188}}}
	}};
	double mur = 2;
	int V = 4;
	NI_LBP<P92g,R1> lbp(mur, V);
	int LBPcode = lbp.convert(array);
	int truth = 40;
	assert( check(test+" Test 17", LBPcode, truth) );
}
{
	Array3D<int,3,3,3> array = {{
		{{{201,225,229},{24,39,14},{114,247,172}}},
		{{{25,66,80},{82,88,212},{149,196,48}}},
		{{{28,188,25},{43,186,28},{125,161,234}}}
	}};
	double mur = 74;
	int V = 3;
	NI_LBP<P92g,R1> lbp(mur, V);
	int LBPcode = lbp.convert(array);
	int truth = 51;
	assert( check(test+" Test 18", LBPcode, truth) );
}
{
	Array3D<int,3,3,3> array = {{
		{{{237,53,29},{157,193,91},{176,216,79}}},
		{{{102,170,230},{61,247,143},{243,180,18}}},
		{{{210,133,141},{53,84,167},{187,175,215}}}
	}};
	double mur = 53;
	int V = 3;
	NI_LBP<P92g,R1> lbp(mur, V);
	int LBPcode = lbp.convert(array);
	int truth = 47;
	assert( check(test+" Test 19", LBPcode, truth) );
}
{
	Array3D<int,3,3,3> array = {{
		{{{101,76,103},{170,200,178},{177,159,107}}},
		{{{55,108,159},{143,38,95},{56,101,37}}},
		{{{62,164,82},{201,93,192},{201,219,137}}}
	}};
	double mur = 254;
	int V = 3;
	NI_LBP<P92g,R1> lbp(mur, V);
	int LBPcode = lbp.convert(array);
	int truth = 93;
	assert( check(test+" Test 20", LBPcode, truth) );
}
{
	Array3D<int,3,3,3> array = {{
		{{{177,106,98},{141,217,173},{176,13,247}}},
		{{{41,97,211},{253,100,139},{95,47,76}}},
		{{{49,28,29},{68,174,88},{158,223,209}}}
	}};
	double mur = 130;
	int V = 3;
	NI_LBP<P92g,R1> lbp(mur, V);
	int LBPcode = lbp.convert(array);
	int truth = 51;
	assert( check(test+" Test 21", LBPcode, truth) );
}
{
	Array3D<int,3,3,3> array = {{
		{{{33,134,166},{114,60,142},{228,228,11}}},
		{{{217,59,224},{188,187,158},{240,173,78}}},
		{{{240,246,66},{80,95,37},{233,51,153}}}
	}};
	double mur = 156;
	int V = 3;
	NI_LBP<P92g,R1> lbp(mur, V);
	int LBPcode = lbp.convert(array);
	int truth = 43;
	assert( check(test+" Test 22", LBPcode, truth) );
}
{
	Array3D<int,3,3,3> array = {{
		{{{0,37,202},{164,186,169},{145,173,243}}},
		{{{96,203,239},{110,98,217},{82,114,190}}},
		{{{179,228,50},{205,199,113},{67,124,147}}}
	}};
	double mur = 105;
	int V = 3;
	NI_LBP<P92g,R1> lbp(mur, V);
	int LBPcode = lbp.convert(array);
	int truth = 49;
	assert( check(test+" Test 23", LBPcode, truth) );
}
{
	Array3D<int,3,3,3> array = {{
		{{{9,33,112},{10,0,165},{245,118,68}}},
		{{{26,140,105},{55,2,218},{109,143,33}}},
		{{{192,6,125},{114,64,91},{76,152,173}}}
	}};
	double mur = 107;
	int V = 4;
	NI_LBP<P92g,R1> lbp(mur, V);
	int LBPcode = lbp.convert(array);
	int truth = 49;
	assert( check(test+" Test 24", LBPcode, truth) );
}
{
	Array3D<int,3,3,3> array = {{
		{{{15,111,13},{205,4,105},{244,101,8}}},
		{{{254,186,127},{47,177,139},{139,197,92}}},
		{{{40,195,36},{191,146,162},{200,249,205}}}
	}};
	double mur = 217;
	int V = 3;
	NI_LBP<P92g,R1> lbp(mur, V);
	int LBPcode = lbp.convert(array);
	int truth = 52;
	assert( check(test+" Test 25", LBPcode, truth) );
}
{
	Array3D<int,3,3,3> array = {{
		{{{177,14,144},{98,130,100},{35,141,171}}},
		{{{83,172,72},{143,102,32},{217,114,131}}},
		{{{142,161,150},{52,157,221},{58,59,88}}}
	}};
	double mur = 18;
	int V = 4;
	NI_LBP<P92g,R1> lbp(mur, V);
	int LBPcode = lbp.convert(array);
	int truth = 50;
	assert( check(test+" Test 26", LBPcode, truth) );
}
{
	Array3D<int,3,3,3> array = {{
		{{{7,177,153},{191,110,107},{9,243,236}}},
		{{{148,92,157},{116,58,53},{232,26,37}}},
		{{{116,215,251},{26,7,121},{144,221,120}}}
	}};
	double mur = 88;
	int V = 3;
	NI_LBP<P92g,R1> lbp(mur, V);
	int LBPcode = lbp.convert(array);
	int truth = 56;
	assert( check(test+" Test 27", LBPcode, truth) );
}
{
	Array3D<int,3,3,3> array = {{
		{{{37,115,54},{75,144,143},{203,109,137}}},
		{{{48,174,207},{113,106,52},{17,186,110}}},
		{{{164,47,112},{117,57,159},{67,141,120}}}
	}};
	double mur = 12;
	int V = 4;
	NI_LBP<P92g,R1> lbp(mur, V);
	int LBPcode = lbp.convert(array);
	int truth = 44;
	assert( check(test+" Test 28", LBPcode, truth) );
}
{
	Array3D<int,3,3,3> array = {{
		{{{183,227,156},{166,131,11},{140,236,1}}},
		{{{235,156,202},{65,230,50},{150,226,104}}},
		{{{106,161,64},{111,73,126},{70,252,218}}}
	}};
	double mur = 99;
	int V = 4;
	NI_LBP<P92g,R1> lbp(mur, V);
	int LBPcode = lbp.convert(array);
	int truth = 50;
	assert( check(test+" Test 29", LBPcode, truth) );
}
{
	Array3D<int,3,3,3> array = {{
		{{{26,190,247},{215,22,129},{73,189,66}}},
		{{{234,62,57},{140,19,221},{22,109,18}}},
		{{{77,107,61},{172,64,37},{148,235,209}}}
	}};
	double mur = 217;
	int V = 3;
	NI_LBP<P92g,R1> lbp(mur, V);
	int LBPcode = lbp.convert(array);
	int truth = 93;
	assert( check(test+" Test 30", LBPcode, truth) );
}
{
	Array3D<int,3,3,3> array = {{
		{{{184,193,152},{169,24,43},{133,233,161}}},
		{{{244,23,62},{37,220,124},{184,196,83}}},
		{{{210,121,117},{116,4,31},{135,53,58}}}
	}};
	double mur = 98;
	int V = 4;
	NI_LBP<P92g,R1> lbp(mur, V);
	int LBPcode = lbp.convert(array);
	int truth = 49;
	assert( check(test+" Test 31", LBPcode, truth) );
}
{
	Array3D<int,3,3,3> array = {{
		{{{235,107,240},{153,101,68},{134,110,218}}},
		{{{58,183,159},{250,64,113},{51,204,157}}},
		{{{198,215,107},{179,136,4},{103,159,4}}}
	}};
	double mur = 92;
	int V = 3;
	NI_LBP<P92g,R1> lbp(mur, V);
	int LBPcode = lbp.convert(array);
	int truth = 49;
	assert( check(test+" Test 32", LBPcode, truth) );
}
{
	Array3D<int,3,3,3> array = {{
		{{{236,227,211},{114,157,98},{141,102,121}}},
		{{{72,191,156},{195,112,50},{55,239,106}}},
		{{{14,51,49},{1,232,60},{174,93,130}}}
	}};
	double mur = 220;
	int V = 3;
	NI_LBP<P92g,R1> lbp(mur, V);
	int LBPcode = lbp.convert(array);
	int truth = 49;
	assert( check(test+" Test 33", LBPcode, truth) );
}
{
	Array3D<int,3,3,3> array = {{
		{{{47,127,186},{94,111,225},{114,89,196}}},
		{{{103,72,247},{231,110,217},{199,103,110}}},
		{{{198,93,40},{204,76,252},{191,32,194}}}
	}};
	double mur = 130;
	int V = 4;
	NI_LBP<P92g,R1> lbp(mur, V);
	int LBPcode = lbp.convert(array);
	int truth = 45;
	assert( check(test+" Test 34", LBPcode, truth) );
}
{
	Array3D<int,3,3,3> array = {{
		{{{20,55,246},{187,83,192},{46,219,109}}},
		{{{132,107,222},{3,80,52},{116,177,246}}},
		{{{50,242,195},{74,251,126},{169,66,243}}}
	}};
	double mur = 207;
	int V = 3;
	NI_LBP<P92g,R1> lbp(mur, V);
	int LBPcode = lbp.convert(array);
	int truth = 49;
	assert( check(test+" Test 35", LBPcode, truth) );
}
{
	Array3D<int,3,3,3> array = {{
		{{{243,248,98},{118,147,60},{77,68,160}}},
		{{{22,21,229},{123,116,14},{197,99,3}}},
		{{{142,120,130},{51,51,15},{39,221,53}}}
	}};
	double mur = 107;
	int V = 4;
	NI_LBP<P92g,R1> lbp(mur, V);
	int LBPcode = lbp.convert(array);
	int truth = 45;
	assert( check(test+" Test 36", LBPcode, truth) );
}
{
	Array3D<int,3,3,3> array = {{
		{{{249,200,72},{163,199,147},{111,249,87}}},
		{{{242,214,200},{123,30,8},{60,97,25}}},
		{{{77,34,51},{163,115,19},{227,225,189}}}
	}};
	double mur = 165;
	int V = 4;
	NI_LBP<P92g,R1> lbp(mur, V);
	int LBPcode = lbp.convert(array);
	int truth = 51;
	assert( check(test+" Test 37", LBPcode, truth) );
}
{
	Array3D<int,3,3,3> array = {{
		{{{97,200,200},{61,151,174},{166,110,128}}},
		{{{90,125,50},{159,79,61},{100,188,194}}},
		{{{156,82,186},{71,96,154},{77,167,75}}}
	}};
	double mur = 90;
	int V = 3;
	NI_LBP<P92g,R1> lbp(mur, V);
	int LBPcode = lbp.convert(array);
	int truth = 45;
	assert( check(test+" Test 38", LBPcode, truth) );
}
{
	Array3D<int,3,3,3> array = {{
		{{{130,22,198},{63,31,68},{72,138,67}}},
		{{{71,180,115},{159,140,13},{213,143,163}}},
		{{{79,73,113},{69,48,128},{206,22,121}}}
	}};
	double mur = 99;
	int V = 4;
	NI_LBP<P92g,R1> lbp(mur, V);
	int LBPcode = lbp.convert(array);
	int truth = 48;
	assert( check(test+" Test 39", LBPcode, truth) );
}
{
	Array3D<int,3,3,3> array = {{
		{{{68,218,143},{46,203,126},{172,135,63}}},
		{{{141,177,194},{138,224,123},{59,18,152}}},
		{{{135,8,119},{84,138,169},{176,137,196}}}
	}};
	double mur = 230;
	int V = 4;
	NI_LBP<P92g,R1> lbp(mur, V);
	int LBPcode = lbp.convert(array);
	int truth = 47;
	assert( check(test+" Test 40", LBPcode, truth) );
}
{
	Array3D<int,3,3,3> array = {{
		{{{36,249,107},{13,155,158},{20,61,212}}},
		{{{192,33,109},{5,130,180},{4,37,1}}},
		{{{86,74,232},{238,72,253},{105,141,7}}}
	}};
	double mur = 45;
	int V = 4;
	NI_LBP<P92g,R1> lbp(mur, V);
	int LBPcode = lbp.convert(array);
	int truth = 49;
	assert( check(test+" Test 41", LBPcode, truth) );
}
{
	Array3D<int,3,3,3> array = {{
		{{{100,125,179},{92,178,5},{17,1,76}}},
		{{{248,148,27},{69,175,138},{89,18,59}}},
		{{{78,44,157},{252,60,79},{129,241,158}}}
	}};
	double mur = 187;
	int V = 4;
	NI_LBP<P92g,R1> lbp(mur, V);
	int LBPcode = lbp.convert(array);
	int truth = 44;
	assert( check(test+" Test 42", LBPcode, truth) );
}
{
	Array3D<int,3,3,3> array = {{
		{{{198,130,166},{55,76,133},{161,66,125}}},
		{{{13,59,68},{81,194,103},{252,160,169}}},
		{{{231,17,1},{181,0,16},{181,25,57}}}
	}};
	double mur = 48;
	int V = 4;
	NI_LBP<P92g,R1> lbp(mur, V);
	int LBPcode = lbp.convert(array);
	int truth = 47;
	assert( check(test+" Test 43", LBPcode, truth) );
}
{
	Array3D<int,3,3,3> array = {{
		{{{83,247,184},{187,150,239},{230,29,11}}},
		{{{31,103,9},{167,217,85},{218,55,94}}},
		{{{209,232,152},{92,71,84},{226,233,114}}}
	}};
	double mur = 18;
	int V = 3;
	NI_LBP<P92g,R1> lbp(mur, V);
	int LBPcode = lbp.convert(array);
	int truth = 46;
	assert( check(test+" Test 44", LBPcode, truth) );
}
{
	Array3D<int,3,3,3> array = {{
		{{{54,30,237},{132,1,59},{162,226,253}}},
		{{{20,177,118},{188,192,137},{174,2,75}}},
		{{{99,202,96},{155,108,138},{175,8,45}}}
	}};
	double mur = 46;
	int V = 4;
	NI_LBP<P92g,R1> lbp(mur, V);
	int LBPcode = lbp.convert(array);
	int truth = 54;
	assert( check(test+" Test 45", LBPcode, truth) );
}
{
	Array3D<int,3,3,3> array = {{
		{{{37,24,231},{32,129,239},{31,135,241}}},
		{{{233,236,26},{42,159,194},{21,220,174}}},
		{{{32,0,61},{196,27,159},{155,21,252}}}
	}};
	double mur = 108;
	int V = 3;
	NI_LBP<P92g,R1> lbp(mur, V);
	int LBPcode = lbp.convert(array);
	int truth = 44;
	assert( check(test+" Test 46", LBPcode, truth) );
}
{
	Array3D<int,3,3,3> array = {{
		{{{23,29,144},{199,30,33},{53,88,211}}},
		{{{182,7,160},{162,178,63},{105,143,193}}},
		{{{62,18,127},{160,160,94},{22,8,167}}}
	}};
	double mur = 143;
	int V = 3;
	NI_LBP<P92g,R1> lbp(mur, V);
	int LBPcode = lbp.convert(array);
	int truth = 93;
	assert( check(test+" Test 47", LBPcode, truth) );
}
{
	Array3D<int,3,3,3> array = {{
		{{{173,209,185},{35,165,173},{4,51,173}}},
		{{{131,24,125},{246,97,193},{74,231,33}}},
		{{{53,199,164},{148,180,147},{25,250,163}}}
	}};
	double mur = 36;
	int V = 3;
	NI_LBP<P92g,R1> lbp(mur, V);
	int LBPcode = lbp.convert(array);
	int truth = 49;
	assert( check(test+" Test 48", LBPcode, truth) );
}
{
	Array3D<int,3,3,3> array = {{
		{{{231,160,11},{228,109,73},{164,242,221}}},
		{{{32,50,0},{162,83,188},{10,46,43}}},
		{{{36,24,4},{166,99,154},{47,94,143}}}
	}};
	double mur = 211;
	int V = 3;
	NI_LBP<P92g,R1> lbp(mur, V);
	int LBPcode = lbp.convert(array);
	int truth = 47;
	assert( check(test+" Test 49", LBPcode, truth) );
}
{
	Array3D<int,3,3,3> array = {{
		{{{160,120,144},{136,97,252},{138,112,206}}},
		{{{40,24,2},{213,47,143},{125,208,51}}},
		{{{172,88,180},{88,232,110},{63,244,179}}}
	}};
	double mur = 51;
	int V = 4;
	NI_LBP<P92g,R1> lbp(mur, V);
	int LBPcode = lbp.convert(array);
	int truth = 53;
	assert( check(test+" Test 50", LBPcode, truth) );
}
{
	Array3D<int,3,3,3> array = {{
		{{{71,48,16},{3,78,231},{75,82,111}}},
		{{{127,192,104},{196,205,103},{14,211,207}}},
		{{{137,7,51},{90,201,187},{133,205,72}}}
	}};
	double mur = 56;
	int V = 3;
	NI_LBP<P92g,R1> lbp(mur, V);
	int LBPcode = lbp.convert(array);
	int truth = 46;
	assert( check(test+" Test 51", LBPcode, truth) );
}
{
	Array3D<int,3,3,3> array = {{
		{{{159,29,155},{90,0,190},{245,61,104}}},
		{{{18,146,225},{223,6,31},{210,107,79}}},
		{{{228,196,34},{178,243,31},{32,92,195}}}
	}};
	double mur = 193;
	int V = 3;
	NI_LBP<P92g,R1> lbp(mur, V);
	int LBPcode = lbp.convert(array);
	int truth = 46;
	assert( check(test+" Test 52", LBPcode, truth) );
}
{
	Array3D<int,3,3,3> array = {{
		{{{50,198,196},{22,79,80},{96,41,183}}},
		{{{83,161,251},{85,246,144},{251,253,4}}},
		{{{19,92,218},{217,13,215},{15,28,140}}}
	}};
	double mur = 229;
	int V = 4;
	NI_LBP<P92g,R1> lbp(mur, V);
	int LBPcode = lbp.convert(array);
	int truth = 43;
	assert( check(test+" Test 53", LBPcode, truth) );
}
{
	Array3D<int,3,3,3> array = {{
		{{{51,5,190},{14,127,229},{34,23,132}}},
		{{{185,63,45},{54,173,144},{177,204,27}}},
		{{{177,207,57},{193,7,118},{150,30,236}}}
	}};
	double mur = 50;
	int V = 3;
	NI_LBP<P92g,R1> lbp(mur, V);
	int LBPcode = lbp.convert(array);
	int truth = 50;
	assert( check(test+" Test 54", LBPcode, truth) );
}
{
	Array3D<int,3,3,3> array = {{
		{{{130,101,66},{179,58,111},{111,220,136}}},
		{{{61,86,235},{71,112,151},{18,204,203}}},
		{{{202,191,229},{3,106,0},{111,26,234}}}
	}};
	double mur = 203;
	int V = 4;
	NI_LBP<P92g,R1> lbp(mur, V);
	int LBPcode = lbp.convert(array);
	int truth = 45;
	assert( check(test+" Test 55", LBPcode, truth) );
}
{
	Array3D<int,3,3,3> array = {{
		{{{169,147,60},{80,229,85},{220,55,80}}},
		{{{100,178,13},{10,229,114},{207,133,20}}},
		{{{148,219,85},{3,245,200},{53,251,163}}}
	}};
	double mur = 234;
	int V = 4;
	NI_LBP<P92g,R1> lbp(mur, V);
	int LBPcode = lbp.convert(array);
	int truth = 46;
	assert( check(test+" Test 56", LBPcode, truth) );
}
{
	Array3D<int,3,3,3> array = {{
		{{{137,9,68},{254,80,17},{250,189,136}}},
		{{{230,208,117},{78,10,204},{93,83,241}}},
		{{{109,1,91},{25,232,229},{62,161,202}}}
	}};
	double mur = 180;
	int V = 3;
	NI_LBP<P92g,R1> lbp(mur, V);
	int LBPcode = lbp.convert(array);
	int truth = 47;
	assert( check(test+" Test 57", LBPcode, truth) );
}
{
	Array3D<int,3,3,3> array = {{
		{{{74,171,247},{192,198,142},{225,131,193}}},
		{{{80,239,128},{87,217,44},{27,39,11}}},
		{{{123,56,145},{49,47,104},{81,163,206}}}
	}};
	double mur = 132;
	int V = 4;
	NI_LBP<P92g,R1> lbp(mur, V);
	int LBPcode = lbp.convert(array);
	int truth = 42;
	assert( check(test+" Test 58", LBPcode, truth) );
}
{
	Array3D<int,3,3,3> array = {{
		{{{181,143,184},{66,66,11},{11,95,140}}},
		{{{209,158,29},{69,143,20},{181,189,201}}},
		{{{189,240,56},{184,232,113},{238,148,101}}}
	}};
	double mur = 226;
	int V = 3;
	NI_LBP<P92g,R1> lbp(mur, V);
	int LBPcode = lbp.convert(array);
	int truth = 47;
	assert( check(test+" Test 59", LBPcode, truth) );
}
{
	Array3D<int,3,3,3> array = {{
		{{{201,25,162},{107,42,220},{7,71,78}}},
		{{{29,150,2},{190,164,37},{145,219,140}}},
		{{{73,165,98},{73,30,203},{37,175,21}}}
	}};
	double mur = 22;
	int V = 3;
	NI_LBP<P92g,R1> lbp(mur, V);
	int LBPcode = lbp.convert(array);
	int truth = 45;
	assert( check(test+" Test 60", LBPcode, truth) );
}
{
	Array3D<int,3,3,3> array = {{
		{{{108,93,6},{179,188,49},{89,101,137}}},
		{{{72,29,189},{202,239,38},{132,21,218}}},
		{{{104,173,46},{2,216,207},{122,43,225}}}
	}};
	double mur = 9;
	int V = 4;
	NI_LBP<P92g,R1> lbp(mur, V);
	int LBPcode = lbp.convert(array);
	int truth = 45;
	assert( check(test+" Test 61", LBPcode, truth) );
}
{
	Array3D<int,3,3,3> array = {{
		{{{235,253,41},{137,216,204},{178,78,102}}},
		{{{222,120,182},{40,176,201},{86,167,21}}},
		{{{55,130,21},{79,201,69},{139,22,145}}}
	}};
	double mur = 199;
	int V = 3;
	NI_LBP<P92g,R1> lbp(mur, V);
	int LBPcode = lbp.convert(array);
	int truth = 93;
	assert( check(test+" Test 62", LBPcode, truth) );
}
{
	Array3D<int,3,3,3> array = {{
		{{{6,128,247},{102,215,202},{34,88,78}}},
		{{{52,17,60},{110,90,9},{223,107,67}}},
		{{{116,81,33},{59,168,162},{144,19,176}}}
	}};
	double mur = 115;
	int V = 4;
	NI_LBP<P92g,R1> lbp(mur, V);
	int LBPcode = lbp.convert(array);
	int truth = 48;
	assert( check(test+" Test 63", LBPcode, truth) );
}
{
	Array3D<int,3,3,3> array = {{
		{{{156,14,68},{135,125,109},{50,163,134}}},
		{{{156,164,143},{239,237,46},{15,251,63}}},
		{{{114,2,85},{127,137,89},{139,233,43}}}
	}};
	double mur = 153;
	int V = 3;
	NI_LBP<P92g,R1> lbp(mur, V);
	int LBPcode = lbp.convert(array);
	int truth = 46;
	assert( check(test+" Test 64", LBPcode, truth) );
}
{
	Array3D<int,3,3,3> array = {{
		{{{103,148,151},{73,94,91},{1,199,128}}},
		{{{138,143,204},{132,35,155},{220,225,78}}},
		{{{152,85,203},{224,39,137},{24,67,246}}}
	}};
	double mur = 105;
	int V = 3;
	NI_LBP<P92g,R1> lbp(mur, V);
	int LBPcode = lbp.convert(array);
	int truth = 48;
	assert( check(test+" Test 65", LBPcode, truth) );
}
{
	Array3D<int,3,3,3> array = {{
		{{{129,103,244},{50,149,99},{57,66,220}}},
		{{{104,1,100},{50,174,37},{120,221,161}}},
		{{{195,129,89},{237,203,218},{201,226,104}}}
	}};
	double mur = 173;
	int V = 3;
	NI_LBP<P92g,R1> lbp(mur, V);
	int LBPcode = lbp.convert(array);
	int truth = 44;
	assert( check(test+" Test 66", LBPcode, truth) );
}
{
	Array3D<int,3,3,3> array = {{
		{{{219,156,73},{121,68,122},{31,180,30}}},
		{{{246,154,111},{64,116,170},{34,114,147}}},
		{{{230,52,107},{86,161,145},{0,10,56}}}
	}};
	double mur = 6;
	int V = 3;
	NI_LBP<P92g,R1> lbp(mur, V);
	int LBPcode = lbp.convert(array);
	int truth = 55;
	assert( check(test+" Test 67", LBPcode, truth) );
}
{
	Array3D<int,3,3,3> array = {{
		{{{184,159,201},{113,154,98},{128,2,187}}},
		{{{121,20,151},{146,70,16},{16,130,47}}},
		{{{202,43,145},{177,70,17},{102,128,8}}}
	}};
	double mur = 24;
	int V = 3;
	NI_LBP<P92g,R1> lbp(mur, V);
	int LBPcode = lbp.convert(array);
	int truth = 49;
	assert( check(test+" Test 68", LBPcode, truth) );
}
{
	Array3D<int,3,3,3> array = {{
		{{{64,236,26},{117,14,231},{166,232,191}}},
		{{{109,182,52},{72,170,37},{140,113,253}}},
		{{{21,54,204},{14,228,121},{139,203,209}}}
	}};
	double mur = 214;
	int V = 4;
	NI_LBP<P92g,R1> lbp(mur, V);
	int LBPcode = lbp.convert(array);
	int truth = 49;
	assert( check(test+" Test 69", LBPcode, truth) );
}
{
	Array3D<int,3,3,3> array = {{
		{{{192,129,132},{123,200,206},{26,56,84}}},
		{{{210,177,187},{208,169,239},{2,227,48}}},
		{{{133,88,158},{46,204,49},{182,59,164}}}
	}};
	double mur = 9;
	int V = 3;
	NI_LBP<P92g,R1> lbp(mur, V);
	int LBPcode = lbp.convert(array);
	int truth = 93;
	assert( check(test+" Test 70", LBPcode, truth) );
}
{
	Array3D<int,3,3,3> array = {{
		{{{198,246,37},{62,205,73},{203,243,50}}},
		{{{201,13,113},{65,189,248},{160,82,129}}},
		{{{77,82,91},{186,86,163},{80,139,174}}}
	}};
	double mur = 59;
	int V = 3;
	NI_LBP<P92g,R1> lbp(mur, V);
	int LBPcode = lbp.convert(array);
	int truth = 43;
	assert( check(test+" Test 71", LBPcode, truth) );
}
{
	Array3D<int,3,3,3> array = {{
		{{{144,14,204},{104,4,131},{62,206,39}}},
		{{{204,70,122},{232,123,193},{192,164,241}}},
		{{{103,123,64},{93,190,211},{248,61,51}}}
	}};
	double mur = 107;
	int V = 3;
	NI_LBP<P92g,R1> lbp(mur, V);
	int LBPcode = lbp.convert(array);
	int truth = 54;
	assert( check(test+" Test 72", LBPcode, truth) );
}
{
	Array3D<int,3,3,3> array = {{
		{{{41,195,74},{219,169,12},{204,233,181}}},
		{{{128,87,91},{95,214,65},{140,122,159}}},
		{{{105,37,167},{168,224,29},{105,66,82}}}
	}};
	double mur = 161;
	int V = 4;
	NI_LBP<P92g,R1> lbp(mur, V);
	int LBPcode = lbp.convert(array);
	int truth = 45;
	assert( check(test+" Test 73", LBPcode, truth) );
}
{
	Array3D<int,3,3,3> array = {{
		{{{246,74,219},{41,35,27},{61,40,145}}},
		{{{197,252,57},{204,107,231},{64,245,31}}},
		{{{105,48,96},{31,129,235},{194,30,249}}}
	}};
	double mur = 49;
	int V = 4;
	NI_LBP<P92g,R1> lbp(mur, V);
	int LBPcode = lbp.convert(array);
	int truth = 45;
	assert( check(test+" Test 74", LBPcode, truth) );
}
{
	Array3D<int,3,3,3> array = {{
		{{{184,83,96},{12,168,211},{113,77,144}}},
		{{{43,19,155},{42,168,59},{148,35,52}}},
		{{{193,249,217},{23,128,200},{11,135,140}}}
	}};
	double mur = 202;
	int V = 3;
	NI_LBP<P92g,R1> lbp(mur, V);
	int LBPcode = lbp.convert(array);
	int truth = 40;
	assert( check(test+" Test 75", LBPcode, truth) );
}
{
	Array3D<int,3,3,3> array = {{
		{{{26,203,190},{251,165,41},{66,195,232}}},
		{{{63,234,247},{220,169,135},{69,154,179}}},
		{{{182,120,156},{30,161,14},{218,45,247}}}
	}};
	double mur = 242;
	int V = 4;
	NI_LBP<P92g,R1> lbp(mur, V);
	int LBPcode = lbp.convert(array);
	int truth = 47;
	assert( check(test+" Test 76", LBPcode, truth) );
}
{
	Array3D<int,3,3,3> array = {{
		{{{43,63,201},{8,165,61},{163,100,29}}},
		{{{138,63,232},{81,132,127},{8,40,128}}},
		{{{129,97,230},{33,232,117},{52,22,192}}}
	}};
	double mur = 27;
	int V = 4;
	NI_LBP<P92g,R1> lbp(mur, V);
	int LBPcode = lbp.convert(array);
	int truth = 45;
	assert( check(test+" Test 77", LBPcode, truth) );
}
{
	Array3D<int,3,3,3> array = {{
		{{{160,158,176},{178,214,175},{33,188,104}}},
		{{{110,248,119},{219,249,36},{253,246,171}}},
		{{{113,90,195},{236,179,188},{224,164,106}}}
	}};
	double mur = 51;
	int V = 3;
	NI_LBP<P92g,R1> lbp(mur, V);
	int LBPcode = lbp.convert(array);
	int truth = 56;
	assert( check(test+" Test 78", LBPcode, truth) );
}
{
	Array3D<int,3,3,3> array = {{
		{{{212,159,181},{136,110,124},{0,15,124}}},
		{{{3,249,220},{34,230,242},{94,8,30}}},
		{{{131,100,91},{147,236,203},{234,200,84}}}
	}};
	double mur = 11;
	int V = 3;
	NI_LBP<P92g,R1> lbp(mur, V);
	int LBPcode = lbp.convert(array);
	int truth = 50;
	assert( check(test+" Test 79", LBPcode, truth) );
}
{
	Array3D<int,3,3,3> array = {{
		{{{246,44,230},{135,116,159},{176,110,247}}},
		{{{191,201,244},{131,228,40},{56,178,172}}},
		{{{1,61,221},{105,77,181},{89,232,179}}}
	}};
	double mur = 243;
	int V = 3;
	NI_LBP<P92g,R1> lbp(mur, V);
	int LBPcode = lbp.convert(array);
	int truth = 45;
	assert( check(test+" Test 80", LBPcode, truth) );
}
{
	Array3D<int,3,3,3> array = {{
		{{{105,99,178},{115,76,200},{171,72,139}}},
		{{{46,191,71},{78,40,99},{48,177,231}}},
		{{{162,67,40},{221,52,7},{60,56,254}}}
	}};
	double mur = 6;
	int V = 3;
	NI_LBP<P92g,R1> lbp(mur, V);
	int LBPcode = lbp.convert(array);
	int truth = 45;
	assert( check(test+" Test 81", LBPcode, truth) );
}
{
	Array3D<int,3,3,3> array = {{
		{{{129,134,58},{225,37,120},{124,6,145}}},
		{{{188,221,177},{116,162,220},{99,205,66}}},
		{{{126,188,43},{158,26,197},{179,101,229}}}
	}};
	double mur = 91;
	int V = 4;
	NI_LBP<P92g,R1> lbp(mur, V);
	int LBPcode = lbp.convert(array);
	int truth = 49;
	assert( check(test+" Test 82", LBPcode, truth) );
}
{
	Array3D<int,3,3,3> array = {{
		{{{105,145,216},{67,174,63},{124,149,225}}},
		{{{231,75,11},{143,242,114},{213,235,85}}},
		{{{60,210,250},{4,226,39},{131,211,188}}}
	}};
	double mur = 91;
	int V = 4;
	NI_LBP<P92g,R1> lbp(mur, V);
	int LBPcode = lbp.convert(array);
	int truth = 44;
	assert( check(test+" Test 83", LBPcode, truth) );
}
{
	Array3D<int,3,3,3> array = {{
		{{{20,43,209},{55,81,175},{200,248,117}}},
		{{{107,168,148},{84,118,90},{245,44,197}}},
		{{{195,75,18},{10,252,132},{60,249,210}}}
	}};
	double mur = 222;
	int V = 3;
	NI_LBP<P92g,R1> lbp(mur, V);
	int LBPcode = lbp.convert(array);
	int truth = 93;
	assert( check(test+" Test 84", LBPcode, truth) );
}
{
	Array3D<int,3,3,3> array = {{
		{{{34,193,199},{227,32,190},{213,58,16}}},
		{{{174,206,45},{168,91,219},{179,2,115}}},
		{{{205,90,203},{29,67,16},{4,133,178}}}
	}};
	double mur = 45;
	int V = 4;
	NI_LBP<P92g,R1> lbp(mur, V);
	int LBPcode = lbp.convert(array);
	int truth = 50;
	assert( check(test+" Test 85", LBPcode, truth) );
}
{
	Array3D<int,3,3,3> array = {{
		{{{139,149,196},{252,164,11},{242,121,107}}},
		{{{188,101,172},{54,86,2},{245,78,9}}},
		{{{164,195,15},{201,54,86},{74,219,131}}}
	}};
	double mur = 247;
	int V = 4;
	NI_LBP<P92g,R1> lbp(mur, V);
	int LBPcode = lbp.convert(array);
	int truth = 54;
	assert( check(test+" Test 86", LBPcode, truth) );
}
{
	Array3D<int,3,3,3> array = {{
		{{{14,17,148},{66,61,10},{104,226,239}}},
		{{{173,241,185},{9,158,47},{196,147,60}}},
		{{{75,127,127},{34,116,176},{207,180,16}}}
	}};
	double mur = 154;
	int V = 4;
	NI_LBP<P92g,R1> lbp(mur, V);
	int LBPcode = lbp.convert(array);
	int truth = 50;
	assert( check(test+" Test 87", LBPcode, truth) );
}
{
	Array3D<int,3,3,3> array = {{
		{{{228,144,211},{60,228,95},{144,140,124}}},
		{{{103,94,49},{241,189,140},{234,153,123}}},
		{{{24,237,134},{159,25,23},{190,154,165}}}
	}};
	double mur = 32;
	int V = 4;
	NI_LBP<P92g,R1> lbp(mur, V);
	int LBPcode = lbp.convert(array);
	int truth = 51;
	assert( check(test+" Test 88", LBPcode, truth) );
}
{
	Array3D<int,3,3,3> array = {{
		{{{247,27,38},{159,227,178},{197,37,143}}},
		{{{18,185,11},{67,218,88},{118,236,20}}},
		{{{87,44,144},{86,198,9},{9,92,161}}}
	}};
	double mur = 200;
	int V = 3;
	NI_LBP<P92g,R1> lbp(mur, V);
	int LBPcode = lbp.convert(array);
	int truth = 48;
	assert( check(test+" Test 89", LBPcode, truth) );
}
{
	Array3D<int,3,3,3> array = {{
		{{{80,113,197},{205,1,115},{59,26,184}}},
		{{{216,58,204},{177,126,43},{174,241,203}}},
		{{{0,19,216},{207,205,217},{207,79,235}}}
	}};
	double mur = 183;
	int V = 3;
	NI_LBP<P92g,R1> lbp(mur, V);
	int LBPcode = lbp.convert(array);
	int truth = 48;
	assert( check(test+" Test 90", LBPcode, truth) );
}
{
	Array3D<int,3,3,3> array = {{
		{{{58,49,184},{126,240,115},{151,58,129}}},
		{{{100,166,151},{134,170,87},{239,223,20}}},
		{{{178,172,188},{25,46,100},{49,235,81}}}
	}};
	double mur = 80;
	int V = 3;
	NI_LBP<P92g,R1> lbp(mur, V);
	int LBPcode = lbp.convert(array);
	int truth = 45;
	assert( check(test+" Test 91", LBPcode, truth) );
}
{
	Array3D<int,3,3,3> array = {{
		{{{203,27,51},{239,211,56},{102,73,219}}},
		{{{78,145,151},{128,41,66},{37,109,230}}},
		{{{99,144,132},{197,164,90},{8,165,96}}}
	}};
	double mur = 183;
	int V = 3;
	NI_LBP<P92g,R1> lbp(mur, V);
	int LBPcode = lbp.convert(array);
	int truth = 48;
	assert( check(test+" Test 92", LBPcode, truth) );
}
{
	Array3D<int,3,3,3> array = {{
		{{{232,79,77},{168,239,18},{21,104,25}}},
		{{{82,192,54},{118,103,153},{36,11,45}}},
		{{{175,170,80},{253,104,35},{88,127,250}}}
	}};
	double mur = 70;
	int V = 4;
	NI_LBP<P92g,R1> lbp(mur, V);
	int LBPcode = lbp.convert(array);
	int truth = 46;
	assert( check(test+" Test 93", LBPcode, truth) );
}
{
	Array3D<int,3,3,3> array = {{
		{{{196,156,213},{93,118,40},{243,28,182}}},
		{{{249,147,120},{162,110,84},{76,112,93}}},
		{{{160,183,116},{178,67,180},{30,236,205}}}
	}};
	double mur = 147;
	int V = 4;
	NI_LBP<P92g,R1> lbp(mur, V);
	int LBPcode = lbp.convert(array);
	int truth = 48;
	assert( check(test+" Test 94", LBPcode, truth) );
}
{
	Array3D<int,3,3,3> array = {{
		{{{225,73,121},{125,185,203},{79,57,140}}},
		{{{29,183,230},{215,221,254},{93,19,202}}},
		{{{56,186,212},{90,152,193},{13,168,236}}}
	}};
	double mur = 93;
	int V = 3;
	NI_LBP<P92g,R1> lbp(mur, V);
	int LBPcode = lbp.convert(array);
	int truth = 46;
	assert( check(test+" Test 95", LBPcode, truth) );
}
{
	Array3D<int,3,3,3> array = {{
		{{{65,28,19},{236,210,24},{188,90,26}}},
		{{{41,32,181},{208,43,192},{195,123,110}}},
		{{{52,106,62},{241,58,176},{192,239,140}}}
	}};
	double mur = 211;
	int V = 4;
	NI_LBP<P92g,R1> lbp(mur, V);
	int LBPcode = lbp.convert(array);
	int truth = 48;
	assert( check(test+" Test 96", LBPcode, truth) );
}
{
	Array3D<int,3,3,3> array = {{
		{{{220,110,66},{76,101,141},{163,191,39}}},
		{{{22,216,237},{166,148,73},{210,70,98}}},
		{{{208,152,164},{60,189,194},{25,197,217}}}
	}};
	double mur = 224;
	int V = 3;
	NI_LBP<P92g,R1> lbp(mur, V);
	int LBPcode = lbp.convert(array);
	int truth = 44;
	assert( check(test+" Test 97", LBPcode, truth) );
}
{
	Array3D<int,3,3,3> array = {{
		{{{225,236,229},{41,16,158},{41,128,136}}},
		{{{118,240,226},{137,81,109},{220,11,61}}},
		{{{65,101,139},{54,248,183},{176,140,224}}}
	}};
	double mur = 122;
	int V = 4;
	NI_LBP<P92g,R1> lbp(mur, V);
	int LBPcode = lbp.convert(array);
	int truth = 47;
	assert( check(test+" Test 98", LBPcode, truth) );
}
{
	Array3D<int,3,3,3> array = {{
		{{{177,153,25},{115,203,226},{174,111,122}}},
		{{{227,181,143},{253,86,229},{92,250,222}}},
		{{{167,49,136},{146,51,41},{169,202,61}}}
	}};
	double mur = 100;
	int V = 3;
	NI_LBP<P92g,R1> lbp(mur, V);
	int LBPcode = lbp.convert(array);
	int truth = 53;
	assert( check(test+" Test 99", LBPcode, truth) );
}
}
