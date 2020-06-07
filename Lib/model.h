/**
 * https://github.com/ssloy/tinyrenderer/blob/master/model.h
 */

#ifndef __MODEL_H__
#define __MODEL_H__

#include <vector>
#include "geometry.cpp"

class Model {
private:
	std::vector<Vec3f> verts_;
	std::vector<std::vector<int> > faces_;
public:
	Model(const char *filename);
	~Model();
	int nverts();
	int nfaces();
	Vec3f vert(int i);
	std::vector<int> face(int idx);
};

#endif //__MODEL_H__

// file ends here

