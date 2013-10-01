#ifndef LOCATION_H
#define LOCATION_H


namespace DoodleBugGameOrtell
{
	class Location
	{
	public:
		Location( );
		Location(int x, int y);
		Location(const Location& other);
		Location& operator=(const Location& other);
		friend bool operator==(const Location& lhs, const Location& rhs);
		friend bool operator!=(const Location& lhs, const Location& rhs);
		int get_xpoint( ) const;
		int get_ypoint( ) const;
		void set_xpoint(const int x);
		void set_ypoint(const int y);

	private:
		int m_x;
		int m_y;
	};
}//DoodleBugGameOrtell
#endif // LOCATION_H
