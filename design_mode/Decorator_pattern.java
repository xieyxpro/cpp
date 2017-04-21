/*
 *孙悟空有七十二般变化，他的每一种变化都给他带来一种附加的本领。
 *他变成鱼儿时，就可以到水里游泳；他变成鸟儿时，就可以在天上飞行。
 *本例中，Component的角色便由鼎鼎大名的齐天大圣扮演；
 *ConcreteComponent的角色属于大圣的本尊，就是猢狲本人；
 *Decorator的角色由大圣的七十二变扮演。
 *而ConcreteDecorator的角色便是鱼儿、鸟儿等七十二般变化。
 */

//抽象构件 大圣
public interface TheGreatestSage {
	public void move();
}

//具体构件 大圣本尊猢狲类
public class Monkey implements TheGreatestSage {
	public void move() {
		System.out.println("Monkey move");
	}
}

//抽象装饰角色 七十二变
public class Change implements TheGreatestSage {
	private TheGreatestSage sage;

	public Change(TheGreatestSage sage) {
		this.sage = sage;
	}

	public void move() {
		sage.move();
	}
}

//具体装饰角色 鱼
public class Fish extends Change {
	public Fish(TheGreatestSage sage) {
		super(sage);
	}

	public void move() {
		System.out.println("Fish move");
	}
}

//具体装饰角色 鸟
public class Bird extends Change {
	public Bird(TheGreatestSage sage) {
		super(sage);
	}

	public void move() {
		System.out.println("Bird move");
	}
}

public class Client {
	public static void main(String[] args) {
		TheGreatestSage sage = new Monkey();

		TheGreatestSage fish = new Fish(new Bird(sage));
		//把大圣从一只猢狲装饰成了一只鸟儿然后又把鸟儿装饰成了一条鱼儿
		fish.move();
	}
}