#include <iostream>
#include <fstream>
#include <string>

int main(){

	std::ifstream original;
	std::ofstream newImage;

	original.open("../build/image.ppm");
	newImage.open("newImg.ppm");
	
	std::string type = "";
	std::string width = "";
	std::string height = "";
	std::string RGB = "";

	if(original.is_open()){
		
		original >> type;
		original >> width;
		original >> height;
		original >> RGB;
	
		newImage << type << std::endl;
		newImage << (width + " " + height).c_str() << std::endl;
		newImage << RGB << std::endl;

		std::string red = "";
		std::string green = "";
		std::string blue = "";
		int r = 0, g = 0, b = 0;
		while(!original.eof()){
		
			original >> red;
			original >> green;
			original >> blue;

			r = std::stoi(red);
			g = std::stoi(green);
			b = std::stoi(blue);

			newImage << r << " " << g << " " << (b * 50) % 255 << std::endl;


		}


		
	


	}


	return 0;
}
