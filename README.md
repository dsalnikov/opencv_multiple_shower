# opencv multiple shower
Class for showing multiple opencv images.

Usage:

	MultipleShower sh(320, 240);
	sh.set_grid(2, 2);
	sh.set_padding(10, 10);
	sh.add(0, 0, saltpepper);
	sh.add(0, 1, canny);
	sh.add(1, 0, image - canny);
	sh.add(1, 1, aswm_mod);
	sh.show();
	sh.save("result.png");
