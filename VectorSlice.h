#pragma once

#include <vector>
template<class T>
class VectorSlice {
	typedef typename std::vector<T>::iterator VINT;
	std::vector<T>& m_mvec;
	VINT m_it;
	VINT m_startit;
	VINT m_endit;
	VINT m_pit;
	unsigned int m_start;
	unsigned int m_end;
	unsigned int m_steps;
	unsigned int m_curr_pos;
public:
	VectorSlice(std::vector<typename T>& pvec, unsigned int pstart=0, int pend=-1, unsigned int psteps = 1):
		m_mvec(pvec),
		m_start(pstart),
		m_end(pend),
		m_steps(psteps),
		m_it(pvec.begin()) {
		if (m_end == -1) {
			m_end  = pvec.size();
		}
		if (m_start > m_end) {
			m_start = m_end;
		}
		if (m_end > m_mvec.size()) {
			m_end = m_mvec.size();
		}
	}
	void reset() {
		m_it = m_mvec.begin();
		m_endit = m_mvec.begin();
		std::advance(m_startit, m_start);
		std::advance(m_endit, m_end);
		m_it = m_startit;
	}
	T& next()
	{
		m_pit = m_it;
		std::advance(m_mvec, m_it);
		return m_pit;
	}
	int curr_pos()
	{
		return std::distance(m_mvec.begin(), m_it);;
	}


};