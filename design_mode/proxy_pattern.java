public interface SaleTowelInterface {
	void sellTowel();
}

//生产类
public class TowelProduce implements SaleTowelInterface {
	private String consumerName;

	TowelProduce(String consumerName) {
		this.consumerName = consumerName;
	}

	void sellTowel() {
		System.out.println("sell to " + consumerName);
	}
}

//代理类
public class TowelSaleProxy implements SaleTowelInterface {
	private TowelProduce tp;

	TowelSaleProxy(String consumerName) {
		tp = new TowelProduce(consumerName);
	}

	void sellTowel() {
		tp.sellTowel();
	}
}