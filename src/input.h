#ifndef _CORE_INPUT_H
#define _CORE_INPUT_H

#define MAX_KEYS    1024
#define MAX_BUTTONS 32

#include <GLFW/glfw3.h>

namespace Core { namespace Input {
	class Mouse {
		public:
			static Mouse& getInstance();
			inline double getX() const { return m_mx; }
			inline double getY() const { return m_my; }
			inline void getPosition(double * x, double * y) const { *x = m_mx; *y = m_my; }
			inline void setX( double x ) { m_mx = x; }
			inline void setY( double y ) { m_my = y; }
			inline void setButtonState( unsigned int button, bool state ) {
				m_buttons[ button ] = state;
			}
			inline bool pressed ( unsigned int button ) const {
				return m_buttons[ button ];
			}
		private:
			// Functions
			Mouse() {
				for (int i = 0; i < MAX_BUTTONS; ++i) {
					m_buttons[i] = false;
				}
			}

			// Vars
			static Mouse m_instance;
			bool   m_buttons[ MAX_BUTTONS ];
			double m_mx;
			double m_my;
	};

	class Keyboard {
		public:
			static Keyboard& getInstance();
			inline void setKeyState( unsigned int key, bool state ) {
				m_keys[ key ] = state;
			}
			inline bool pressed ( unsigned int key ) const {
				return m_keys[ key ];
			}
		private:
			// Functions
			Keyboard() {
				for ( int i = 0; i < MAX_KEYS; ++i )
					m_keys[i] = false;
			}

			// Vars
			static Keyboard m_instance;
			bool m_keys[ MAX_KEYS ];
	}; 
} } 

#endif // _CORE_INPUT_H