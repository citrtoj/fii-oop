

/*A* A::instance = 0;

A::A() : path("") {}

A::~A() {}

A* A::GetInstance() {
	if (instance == nullptr) {
		instance = new A;
	}
	return instance;
}

void A::DestroyInstance() {
	delete instance;
}

void A::Write(std::string mesaj) {
	std::ofstream fout(path, std::ios_base::app);
	fout << mesaj;
	fout.close();
}

void A::ChangePath(std::string newPath) {
	path = newPath;
	std::transform(path.begin(), path.end(), path.begin(), [](char c) {return tolower(c); });
}

Baza::Baza() : a(5) {
	A::GetInstance()->Write("sunt in constructor Baza\n");
}

Derivat::Derivat() : a(8) {
	A::GetInstance()->Write("sunt in constructor Derivat\n");
}

void Baza::Calcul() {
	a *= 3;
	A::GetInstance()->Write("sunt in Calcul Baza\n");
}

void Derivat::Calcul() {
	a *= 10;
	A::GetInstance()->Write("sunt in Calcul Derivat\n");
}

int Baza::Get() {
	return a;
	A::GetInstance()->Write("sunt in get Baza\n");

}

int Derivat::Get() {
	return a;
	A::GetInstance()->Write("sunt in get Derivat\n");
}

Baza::~Baza() {

	A::GetInstance()->Write("sunt in destructor Baza\n");
}

Derivat::~Derivat() {

	A::GetInstance()->Write("sunt in destructor Derivat\n");
}
*/