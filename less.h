/*
 * less.h
 *
 *  Created on: Jun 7, 2012
 *      Author: f
 */

#ifndef LESS_H_
#define LESS_H_

template<class T>
class Less {
public:
	bool operator()(const T& lhs, const T& rhs) {
		return lhs < rhs;
	}
};

#endif /* LESS_H_ */
