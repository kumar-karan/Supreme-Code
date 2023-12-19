public class TestClass {
    private static String[] aaa;

    public TestClass(String s) {
        this.aaa = s.split("");
    }

    private class TestClass1 implements TestClass2 {
        private int i = 0;

        public boolean a() {
            return i == aaa.length;
        }

        public String c() {
            return aaa[aaa.length - (i + 1)];
        }

        public void next() {
            if (i < aaa.length) {
                ++i;
            }
        }
    }

    public TestClass2 m1() {
        return new TestClass1();
    }

    public static void main(String[] args) {
        TestClass sa = new TestClass("eee ccc " + "ddd eee");
        TestClass2 m1 = sa.m1();

        while (!m1.a()) {
            System.out.print(m1.c() + "'");
            m1.next();
        }
    }

    interface TestClass2 {
        boolean a();

        String c();

        void next();
    }
}
