#include <string>
#include <QString>


namespace MYLIB
{
	class MyLIB
	{
		public:
			MyLIB();

			~MyLIB();

			std::string get_string();

			void set_string(std::string s);

		private:
			QString s_;
	};
}
