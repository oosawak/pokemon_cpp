#include <string>
#include <iostream>
#include <random>
class Pokemon {
public:
	Pokemon();
	Pokemon(std::string name,int level,int type,int hp,
		int atk, int def,int special_atk,int special_def,int agi) ;	
	~Pokemon();
	int GetAtackP(int waza,int d);
	int Battle(int atack_point);
	std::string getName() {
		return name;
	}
	int getLevel() {
		return level;
	}
	int getAgi() {
		return agi;
	}
private:
	std::string name;	// 文字列
	int level;		// レベル
	int type;		// 属性
	int hp;			// HP
	int atk;		// こうげぎ
	int def;		// 防御
	int special_atk;	// とくこう
	int special_def;	// とくぼう
	int agi;		// すばやさ
	int waza[4];		// 技リスト
};
// コンストラクタ
Pokemon::Pokemon() {
	this->name = "フロウ"; this->level = 29; this->hp = 183;
	this->atk = 43; this->def = 39; this->special_atk = 46;
    this->special_def = 39; this->agi = 49;
}
Pokemon::Pokemon(std::string name,int level,int type,int hp,
	int atk, int def,int special_atk,int special_def,int agi) {
	this->name = name; this->level = level; this->hp = hp;
	this->atk = atk; this->def = def; 
	this->special_atk = special_atk; this->special_def = special_atk; this->agi = agi;
}
// デストラクタ
Pokemon::~Pokemon() {
}
int Pokemon::GetAtackP(int waza,int d) {
	return atk*(waza/100+1)+d;
}
// 攻撃値を引数として呼び出すと戻り値でHPを返す
int Pokemon::Battle(int atack_point) {
	int buttle_point = atack_point - this->def;
	if(buttle_point>0) { hp = hp - buttle_point; }
	if(this->hp < 0) { hp = 0 ; }
	std::cout 
	<< this->getName() << "は" << buttle_point << "のダメージ" << std::endl
	<< this->getName() << "のHPは" << hp << std::endl
	<< std::endl;
	return hp;
}

// サイコロ関数
// 引数で渡された d面体のサイコロを再現する。
// 6面体なら１から６の数字を返す。
int dice(int d) {
	std::mt19937 engine{ std::random_device{}() };
	std::uniform_int_distribution<int> dist(1, d);
	auto n = dist(engine);
    return n ;
}
int main() {
	// coutの実験
	std::cout << "[[ポケモンバトル]]" << dice(6) << dice(6) << dice(6)<< std::endl << std::endl;
	// ポケモンAオブジェクトを生成
	Pokemon pokemon_a = Pokemon("フロウA",30,1,183,43,39,46,39,49);
	std::cout << "ポケモンAのステータス" << std::endl
		<< "名前:" << pokemon_a.getName() << std::endl	// 文字列
		<< "レベル:" << pokemon_a.getLevel() << std::endl	// 文字列
		<< std::endl ;
	// ポケモンBオブジェクトを生成
	Pokemon pokemon_b = Pokemon("フロウB",28,1,202,40,42,43,37,51);
	std::cout << "ポケモンBのステータス" << std::endl
		<< "名前:" << pokemon_b.getName() << std::endl	// 文字列
		<< "レベル:" << pokemon_b.getLevel() << std::endl	// 文字列
		<< std::endl ;
	std::cout << "ポケモンバトル開始します" << std::endl << std::endl;
	Pokemon pokemon[2];
	// どちらから攻撃か決定してバトルを始める
	if(pokemon_a.getAgi() > pokemon_b.getAgi()) {
		pokemon[0] = pokemon_a ; pokemon[1] = pokemon_b ;
	} else {
		pokemon[1] = pokemon_a ; pokemon[0] = pokemon_b ;
	}
	while(true) {
		// 先行のポケモンの攻撃
    		// 攻撃値を取得する。 技は40固定
		std::cout 
			<< pokemon[0].getName() 
			<< "の攻撃" <<std::endl
			<< std::endl;
	
		int d = dice(6) ;
		int attack_point = pokemon[0].GetAtackP(40,d);
		// 防御ポケモンにダメージを入れる
		int defence_hp = pokemon[1].Battle(attack_point);
		if (defence_hp <= 0) {
			std::cout << pokemon[1].getName() << "は倒れました" << std::endl
			<< std::endl ;
			std::cout << pokemon[0].getName() << "が勝利しました" << std::endl
			<< std::endl ;
			exit(0);
		}

		// 後攻ポケモンの攻撃
		// 攻撃値を取得する。 技は40固定

		std::cout 
			<< pokemon[1].getName() 
			<< "の攻撃" <<std::endl
			<< std::endl;
		d = dice(6) ;
		attack_point = pokemon[1].GetAtackP(40,d);

		// 防御ポケモンにダメージを入れる
		defence_hp = pokemon[0].Battle(attack_point);
		if (defence_hp <= 0) {
			// 防御ポケモンは倒れました。
			std::cout << pokemon[0].getName() << "は倒れました" << std::endl
			<< std::endl ;
			std::cout << pokemon[1].getName() << "が勝利しました" << std::endl
			<< std::endl ;
			exit(0);
		}
	}
}
