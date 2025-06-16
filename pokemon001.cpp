#include <string>

class Pokemon {
public:
	int GetAtack(int waza);
	int SetAtack(int atack_point);
private:
	std::string name;	// 文字列
	int level;			// レベル
	int type;			// 属性
	int hp;				// HP
	int atk;			// こうげぎ
	int def;			// 防御
	int special_atk;	// とくこう
	int special_def;	// とくぼう
	int agi;			// すばやさ
	int waza[];			// 技リスト
};

// コンストラクタ
Pokemon::Pokemon() {
	this->name = "フロウ";
	this->level = 29;
	this->hp = 183;
	this->atk = 43;
	this->def = 39;
	this->special_atk = 46;
	this->special_def = 39;
	this->agi = 49;
}

// デストラクタ
Pokemon::~Pokemon() {

}


int Pokemon::GetAtack(int waza) {
	return atk*(waza/100+1);
}

// 攻撃値を引数として呼び出すと戻り値でHPを返す
int Pokemon::SetAtack(int atack_point) {
	int buttle_point = atack_point - this->def;
	if(buttle_point>0) {
		this->hp - buttle_point;
	}
	return this->hp;
}

int main() {
	// ポケモンAオブジェクトを生成
	Pokemon pokemon_a;

	// ポケモンBオブジェクトを生成
	Pokemon pokemon_b;

	// どちらから攻撃か決定してバトルを始める
	// if(pokemon_a.GetAgi > pokemon_b.GetAgi) {
	// } else {
	// }

	// 先行のポケモンの攻撃
    // 攻撃値を取得する。 技は40固定

	int attack_point = pokemon_a.GetAtack(40);

	// 防御ポケモンにダメージを入れる
	int defence_hp = pokemon_b.SetAtack(attack_point);

	if (defence_hp <= 0) {
		// 防御ポケモンは倒れました。

	}

	// 後攻ポケモンの攻撃
	// 攻撃値を取得する。 技は40固定

	attack_point = pokemon_b.GetAtack(40);
	// 防御ポケモンにダメージを入れる
	defence_hp = pokemon_a.SetAtack(attack_point);
	if (defence_hp <= 0) {
		// 防御ポケモンは倒れました。

	}
}
