#pragma once

float vertices_Floor[] =
{
	//pos					//tex			//nor
	-1.0f, 1.0f, 0.0f,		 0.0f, 1.0f,	0.0f, 0.0f, -1.0f,
	 1.0f, 1.0f, 0.0f,		 1.0f, 1.0f,	0.0f, 0.0f, -1.0f,
	 1.0f,-1.0f, 0.0f,		 1.0f, 0.0f,	0.0f, 0.0f, -1.0f,

	-1.0f, 1.0f, 0.0f,		 0.0f, 1.0f,	0.0f, 0.0f, -1.0f,
	 1.0f,-1.0f, 0.0f,		 1.0f, 0.0f,	0.0f, 0.0f, -1.0f,
	-1.0f,-1.0f, 0.0f,		 0.0f, 0.0f,	0.0f, 0.0f, -1.0f,

	-1.0f, 1.0f, 0.02f,		 0.0f, 1.0f,	0.0f, 0.0f, 1.0f,
	 1.0f, 1.0f, 0.02f,		 1.0f, 1.0f,	0.0f, 0.0f, 1.0f,
	 1.0f,-1.0f, 0.02f,		 1.0f, 0.0f,	0.0f, 0.0f, 1.0f,

	-1.0f, 1.0f, 0.02f,		 0.0f, 1.0f,	0.0f, 0.0f, 1.0f,
	 1.0f,-1.0f, 0.02f,		 1.0f, 0.0f,	0.0f, 0.0f, 1.0f,
	-1.0f,-1.0f, 0.02f,		 0.0f, 0.0f,	0.0f, 0.0f, 1.0f,

	 1.0f,-1.0f, 0.0f,		 0.0f, 0.0f,	1.0f, 0.0f, 0.0f,
	 1.0f, 1.0f, 0.0f,		 1.0f, 0.0f,	1.0f, 0.0f, 0.0f,
	 1.0f,-1.0f, 0.02f,		 0.0f, 0.02f,	1.0f, 0.0f, 0.0f,

	 1.0f, 1.0f, 0.02f,		 0.0f, 0.0f,	1.0f, 0.0f, 0.0f,
	 1.0f,-1.0f, 0.02f,		 1.0f, 0.02,	1.0f, 0.0f, 0.0f,
	 1.0f, 1.0f, 0.0f,		 0.0f, 0.02f,	1.0f, 0.0f, 0.0f,

	 -1.0f,-1.0f, 0.0f,		 0.0f, 0.0f,	-1.0f, 0.0f, 0.0f,
	 -1.0f, 1.0f, 0.0f,		 1.0f, 0.0f,	-1.0f, 0.0f, 0.0f,
	 -1.0f,-1.0f, 0.02f,	0.0f, 0.02f,	-1.0f, 0.0f, 0.0f,

	 -1.0f, 1.0f, 0.02f,	0.0f, 0.0f,		-1.0f, 0.0f, 0.0f,
	 -1.0f,-1.0f, 0.02f,	1.0f, 0.02,		-1.0f, 0.0f, 0.0f,
	 -1.0f, 1.0f, 0.0f,		0.0f, 0.02f,	-1.0f, 0.0f, 0.0f,

	 -1.0f,1.0f, 0.0f,		 0.0f, 0.0f,	0.0f, 1.0f, 0.0f,
	 1.0f, 1.0f, 0.0f,		 1.0f, 0.0f,	0.0f, 1.0f, 0.0f,
	 -1.0f,1.0f, 0.02f,		 0.0f, 0.02f,	0.0f, 1.0f, 0.0f,

	 1.0f, 1.0f, 0.02f,		 0.0f, 0.0f,	0.0f, 1.0f, 0.0f,
	 -1.0f,1.0f, 0.02f,		 1.0f, 0.02,	0.0f, 1.0f, 0.0f,
	 1.0f, 1.0f, 0.0f,		 0.0f, 0.02f,	0.0f, 1.0f, 0.0f,

	 -1.0f,-1.0f, 0.0f,		 0.0f, 0.0f,	0.0f, -1.0f, 0.0f,
	 1.0f, -1.0f, 0.0f,		 1.0f, 0.0f,	0.0f, -1.0f, 0.0f,
	 -1.0f,-1.0f, 0.02f,	 0.0f, 0.02f,	0.0f, -1.0f, 0.0f,

	 1.0f, -1.0f, 0.02f,	0.0f, 0.0f,		0.0f, -1.0f, 0.0f,
	 -1.0f,-1.0f, 0.02f,	1.0f, 0.02,		0.0f, -1.0f, 0.0f,
	 1.0f, -1.0f, 0.0f,		0.0f, 0.02f,	0.0f, -1.0f, 0.0f,



};
float vertices_crystal[] =
{
	//pos
	//top					//tex			//nor
	0.15f, 0.00f, 0.15f,	0.0f, 0.0f,		0.0525f, 0.0300f, 0.0175f,
	0.20f, 0.00f, 0.00f,	1.0f, 0.0f,		0.0525f, 0.0300f, 0.0175f,
	0.00f, 0.35f, 0.00f,	0.5f, 1.0f,		0.0525f, 0.0300f, 0.0175f,

	0.15f, 0.00f, 0.15f,	0.0f, 0.0f,		0.0175f, 0.0300f, 0.0525f,
	0.00f, 0.00f, 0.20f,	1.0f, 0.0f,		0.0175f, 0.0300f, 0.0525f,
	0.00f, 0.35f, 0.00f,	0.5f, 1.0f,		0.0175f, 0.0300f, 0.0525f,

	//bottom
	0.15f, 0.00f, 0.15f,	0.0f, 0.0f,		0.0300f,-0.0300f, 0.0100f,
	0.20f, 0.00f, 0.00f,	1.0f, 0.0f,		0.0300f,-0.0300f, 0.0100f,
	0.00f,-0.20f, 0.00f,	0.5f, 1.0f,		0.0300f,-0.0300f, 0.0100f,

	0.15f, 0.00f, 0.15f,	0.0f, 0.0f,		0.0100f,-0.0300f, 0.0300f,
	0.00f, 0.00f, 0.20f,	1.0f, 0.0f,		0.0100f,-0.0300f, 0.0300f,
	0.00f,-0.20f, 0.00f,	0.5f, 1.0f,		0.0100f,-0.0300f, 0.0300f

};
float vertices_pedestal[] =
{
	//pos
	//top_first				//tex			//normal
	0.00f, 0.10f, 0.00f,	0.0f, 0.0f,		0.0f, 1.0f, 0.0f,	
	0.30f, 0.10f, 0.30f,	1.0f, 1.0f,		0.0f, 1.0f, 0.0f,
	0.15f, 0.10f, 0.00f,	0.5f, 0.0f,		0.0f, 1.0f, 0.0f,

	0.00f, 0.10f, 0.00f,	0.0f, 0.0f,		0.0f, 1.0f, 0.0f,
	0.30f, 0.10f, 0.30f,	1.0f, 1.0f,		0.0f, 1.0f, 0.0f,
	0.00f, 0.10f, 0.15f,	0.0f, 0.5f,		0.0f, 1.0f, 0.0f,

	//buttom_first
	0.00f, 0.05f, 0.00f,	0.0f, 0.0f,		0.0f,-1.0f, 0.0f,
	0.30f, 0.05f, 0.30f,	1.0f, 1.0f,		0.0f,-1.0f, 0.0f,
	0.15f, 0.05f, 0.00f,	0.5f, 0.0f,		0.0f,-1.0f, 0.0f,

	0.00f, 0.05f, 0.00f,	0.0f, 0.0f,		0.0f,-1.0f, 0.0f,
	0.30f, 0.05f, 0.30f,	1.0f, 1.0f,		0.0f,-1.0f, 0.0f,
	0.00f, 0.05f, 0.15f,	0.0f, 0.5f,		0.0f,-1.0f, 0.0f,

	//side_first
	0.15f, 0.10f, 0.00f,	0.0f, 0.0f,		0.0150f, 0.0000f,-0.0075f,
	0.15f, 0.05f, 0.00f,	0.0f, 0.5f,		0.0150f, 0.0000f,-0.0075f,
	0.30f, 0.10f, 0.30f,	1.0f, 0.0f,		0.0150f, 0.0000f,-0.0075f,

	0.30f, 0.05f, 0.30f,	0.0f, 0.0f,		0.0150f, 0.0000f,-0.0075f,
	0.30f, 0.10f, 0.30f,	0.0f, 0.5f,		0.0150f, 0.0000f,-0.0075f,
	0.15f, 0.05f, 0.00f,	1.0f, 0.0f,		0.0150f, 0.0000f,-0.0075f,

	0.00f, 0.10f, 0.15f,	0.0f, 0.0f,		-0.0075f,0.0000f, 0.0150f,
	0.30f, 0.10f, 0.30f,	1.0f, 0.0f,		-0.0075f,0.0000f, 0.0150f,
	0.00f, 0.05f, 0.15f,	0.0f, 0.5f,		-0.0075f,0.0000f, 0.0150f,

	0.00f, 0.05f, 0.15f,	1.0f, 0.0f,		-0.0075f,0.0000f, 0.0150f,
	0.30f, 0.10f, 0.30f,	0.0f, 0.5f,		-0.0075f,0.0000f, 0.0150f,
	0.30f, 0.05f, 0.30f,	0.0f, 0.0f,		-0.0075f,0.0000f, 0.0150f
};
float vertices_light_box[] =
{
	//pos					//tex			//nor
	//bottom_triangle_first
	 1.0f, 0.0f,-1.0f,		0.0f, 0.0f,		0.0f,-1.0f, 0.0f,
	 1.0f, 0.0f, 1.0f,		1.0f, 0.0f,		0.0f,-1.0f, 0.0f,
	-1.0f, 0.0f,-1.0f,		0.0f, 1.0f,		0.0f,-1.0f, 0.0f,
	//bottom_triangle_second
	 1.0f, 0.0f, 1.0f,		1.0f, 0.0f,		0.0f,-1.0f, 0.0f,
	-1.0f, 0.0f,-1.0f,		0.0f, 1.0f,		0.0f,-1.0f, 0.0f,
	-1.0f, 0.0f, 1.0f,		0.0f, 0.0f,		0.0f,-1.0f, 0.0f,
	//left
	-1.0f, 0.0f,-1.0f,		0.0f, 0.0f,		-1.0f,1.0f,0.0f,
	-1.0f, 0.0f, 1.0f,		1.0f, 0.0f,		-1.0f,1.0f,0.0f,
	 0.0f, 1.0f, 0.0f,		0.5f, 1.0f,		-1.0f,1.0f,0.0f,
	 //right
	  1.0f, 0.0f,-1.0f,		0.0f, 0.0f,		1.0f,1.0f,0.0f,
	  1.0f, 0.0f, 1.0f,		1.0f, 0.0f,		1.0f,1.0f,0.0f,
	  0.0f, 1.0f, 0.0f,		0.5f, 1.0f,		1.0f,1.0f,0.0f,
	 //front
	  1.0f, 0.0f, 1.0f,		0.0f, 0.0f,		0.0f,1.0f,1.0f,
	 -1.0f, 0.0f, 1.0f,		1.0f, 0.0f,		0.0f,1.0f,1.0f,
	  0.0f, 1.0f, 0.0f,		0.5f, 1.0f,		0.0f,1.0f,1.0f,
	//back
	  1.0f, 0.0f, -1.0f,	0.0f, 0.0f,		0.0f,1.0f,-1.0f,
	 -1.0f, 0.0f, -1.0f,	1.0f, 0.0f,		0.0f,1.0f,-1.0f,
	  0.0f, 1.0f, 0.0f,		0.5f, 1.0f,		0.0f,1.0f,-1.0f,
};