class A {
    static printStatic = () => {
        console.log("Função estática")
    }
}

class B extends A {

}

B.printStatic()