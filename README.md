# opencv multiple shower
Class for showing multiple opencv images.

Usage:

	MultipleShower sh(320, 240);
	//set 2x2 grid
	sh.set_grid(2, 2);
	//set vertical and horizontal padding to 10px
	sh.set_padding(10, 10);
	//add images to specified positions
	sh.add(0, 0, saltpepper);
	sh.add(0, 1, canny);
	sh.add(1, 0, image - canny);
	sh.add(1, 1, aswm_mod);
	//show image
	sh.show();
	//save image to file
	sh.save("result.png");

Here is an example result:
![alt tag](https://raw.githubusercontent.com/lamazavr/opencv_multiple_shower/master/shower.png)
