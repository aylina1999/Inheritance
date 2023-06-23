#include<iostream>
#include<string>
using std::cin;
using std::cout;
using std::endl;


#define HUMAN_TAKE_PARAMETERS const std::string& last_name, const std::string& first_name, unsigned int age
#define HUMAN_GIVE_PARAMETERS  last_name, first_name, age

class Human
{
	std::string last_name;
	std::string first_name;
	unsigned int age;
public:
	const std::string& get_last_name()const
	{
		return last_name;
	}
	const std::string& get_first_name()const
	{
		return first_name;
	}
	unsigned int get_age()const
	{
		return age;
	}
	void set_last_name(const std::string& last_name)
	{
		this->last_name = last_name;
	}
	void set_first_name(const std::string& first_name)
	{
		this->first_name = first_name;
	}
	void set_age(unsigned int age)
	{
		this->age = age;
	}
	//               Constructors:
	Human(HUMAN_TAKE_PARAMETERS)
	{
		set_last_name(last_name);
		set_first_name(first_name);
		set_age(age);
		cout << "HConstructor:\t" << this << endl;
	}
	~Human()
	{
		cout << "HDestructor:\t" << this << endl;
	}

	void info()const
	{
		cout << last_name << " " << first_name << " " << age << " y/o." << endl;
	}

};

#define STUDENT_TAKE_PARAMETERS  const std::string& speciality, const std::string& group, double rating, double attendance
#define STUDENT_GIVE_PARAMETERS  speciality, group, rating, attendance
class Student : public Human
{
	std::string speciality;
	std::string group;
	double rating;      //успеваемость
	double attendance;  //посещаемость
public:
	const std::string& get_speciality()const
	{
		return speciality;
	}
	const std::string& get_group()const
	{
		return group;
	}
	double get_rating()const
	{
		return rating;
	}
	double get_attendance()const
	{
		return attendance;
	}

	void set_speciality(const std::string& speciality)
	{
		this->speciality = speciality;
	}
	void set_group(const std::string& group)
	{
		this->group = group;
	}
	void set_rating(double rating)
	{
		this->rating = rating;
	}
	void set_attendance(double attendance)
	{
		this->attendance = attendance;
	}
	//            Constructor:
	Student(HUMAN_TAKE_PARAMETERS,	STUDENT_TAKE_PARAMETERS):Human(HUMAN_GIVE_PARAMETERS)
	{
		set_speciality(speciality);
		set_group(group);
		set_rating(rating);
		set_attendance(attendance);
		cout << "SConstructor:\t" << this << endl;
	}
	~Student()
	{
		cout << "SDestructor:\t" << this << endl;
	}

	void info()const
	{
		Human::info();
		cout << speciality << ", " << group << ", rating: " << rating << ", attendance:" << attendance << endl;
	}
};

#define TEACHER_TAKE_PARAMETERS const std::string& spaciality, unsigned int experience, const std::string& skill, double rating
#define TEACHER_GIVE_PARAMETERS spaciality, experience, skill, rating
class Teacher :public Human
{
	std::string speciality;
	unsigned int experience;
	std::string skill;
	double rating;
public:
	const std::string& get_speciality()const
	{
		return speciality;
	}
	unsigned int get_experience()const
	{
		return experience;
	}
	const std::string& get_skill()const
	{
		return skill;
	}
	double get_rating()const
	{
		return rating;
	}

	void set_speciality(const std::string& speciality)
	{
		this->speciality = speciality;
	}
	void set_experience(unsigned int experience)
	{
		this->experience = experience;
	}
	void set_skill(const std::string& skill)
	{
		this->skill = skill;
	}
	void set_rating(double rating)
	{
		this->rating = rating;
	}

	//        Comstructors:
	Teacher(HUMAN_TAKE_PARAMETERS,	TEACHER_TAKE_PARAMETERS) :Human(HUMAN_GIVE_PARAMETERS)
	{
		set_speciality(speciality);
		set_experience(experience);
		set_skill(skill);
		set_rating(rating);
		cout << "TConstructor:\t" << this << endl;
	}
	~Teacher()
	{
		cout << "TDestructor:\t" << this << endl;
	}

	void info()const
	{
		Human::info();
		cout << speciality << ", " << "experience: " << experience << skill << ", " << ", rating: " << rating << endl;
	}
};


class Graduate :public Student
{
	std::string subject;
public:
	const std::string& get_subject()const
	{
		return subject;
	}
	void set_subject(const std::string& subject)
	{
		this->subject = subject;
	}
	Graduate(HUMAN_TAKE_PARAMETERS, STUDENT_TAKE_PARAMETERS, const std::string& subject)
		:Student(HUMAN_GIVE_PARAMETERS, STUDENT_GIVE_PARAMETERS)
	{
		set_subject(subject);
		cout << "GConstructor:\t" << this << endl;
	}
	~Graduate()
	{
		cout << "GDestructor:\t" << this << endl;
	}

	void info()const
	{
		Student::info();
		cout << "Subject: " << subject << endl;
	}
};

void main()
{
	setlocale(LC_ALL, "");
	/*Human human("Тупенко", "Василий", 18);
	human.info();*/

	Student stud("Pinkman", "Jassie", 25, "Chemistry", "WW_220", 95, 99);
	stud.info();

	Teacher teacher("Grey", "Ivan", 45, "Maths", 20, 98);
	teacher.info();

	Graduate grad("Schreder", "Hank", 40, "Criminalistic", "OBN", 90, 70, "How to catch Heisenberg");
	grad.info();
}