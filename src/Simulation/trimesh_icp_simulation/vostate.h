#pragma once

class VOState
{
public:
	VOState();
	~VOState();

	inline void IncFrame() { ++m_frame; }
	inline int Frame() { return m_frame; }
	inline bool FirstFrame() { return m_first_frame; }
	inline void SetFirstFrame(bool first) { m_first_frame = first; }
	inline bool RelocationState() { return m_lost_times > 2; }
	inline void ResetRelocation() { m_lost_times = 0; }
	inline void IncreLostTimes() { ++m_lost_times; }
protected:
	bool m_first_frame;
	int m_frame;
	int m_lost_times;
};