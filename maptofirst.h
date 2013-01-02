/*
 * maptofirst.h
 *
 *  Created on: Jun 7, 2012
 *      Author: f
 */

#ifndef MAPTOFIRST_H_
#define MAPTOFIRST_H_
#include "pair.h"

template<class T, class U, template<typename> class Order >
class MapToFirst{
public:
	bool operator()(Pair<T,U>& lhs, Pair<T,U>& rhs) {
		Order<T> greaterT;
		return greaterT(lhs.first(), rhs.first());
	}
};


#endif /* MAPTOFIRST_H_ */
