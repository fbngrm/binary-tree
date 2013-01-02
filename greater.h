/*
 * greater.h
 *
 *  Created on: Jun 7, 2012
 *      Author: f
 */

#ifndef GREATER_H_
#define GREATER_H_

template<class T>
class Greater {
public:
	bool operator()(const T& lhs, const T& rhs) {
		return rhs < lhs;
	}
};



#endif /* GREATER_H_ */
