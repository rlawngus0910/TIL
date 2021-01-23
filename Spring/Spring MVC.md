# Spring MVC

### MVC란?

- MVC는 Model-View-Controller의 약자
- Model : 뷰가 렌더링하는데 필요한 데이터이다. ex) 사용자가 요청한 상품 목록, 주문 내역
- View : 실제로 보이는 부분, 모델을 사용해 렌더링을 한다. JSP, JSF, PDF, XML 등으로 결과를 표현한다.
- Controller : 컨트롤러는 사용자의 액션에 응답하는 컴포넌트이다. 모델을 업데이트하고 다른 액션들을 수행.



### MVC Model Architecture

![img](https://cphinf.pstatic.net/mooc/20180219_149/15190034013354diDI_PNG/3.png)

- 클라이언트가 보내는 모든 요청을 프론트 컨트롤러 (서블릿)가 다 받는다. -> 프론트 컨트롤러는 하나만 존재함.
- 프론트 컨트롤러의 장점 
  - 프론트 컨트롤러가 없으면 클라이언트의 요청이 컨트롤러로 이동하게 된다.
  - 이렇게 되면 1개의 요청 당 1개의 서블릿을 만들어야 하므로 유지보수가 어려워지고, 코드 가독성, 개발의 효율이 떨어진다.
  - 따라서, 프론트 컨트롤러를 사용하면 개발 및 유지보수의 효율을 극대화시킬 수 있다.
- 프론트 컨트롤러는 요청만 받고 실제 일은 컨트롤러에게 위임한다. -> 이런 컨트롤러 클래스는 핸들러 클래스라고도 불림.
- 컨트롤러는 Java Bean 등을 이용해서 결과를 만들어내고 모델에다가 담는다. 이를 프론트 컨트롤러에게 보내면 알맞은 뷰에게 모델을 전달해서 결과를 출력한다.
- 이 Architecture가 Spring의 Web 모듈에 구현이 되어있다. -> 이를 Spring MVC라고 한다.



# Spring MVC 설정

### pom.xml

Maven Project Build 후 pom.xml의 properties에 다음과 같은 코드를 입력한다.

`<spring.version> 4.3.5.RELEASE</spring.version>`

 pom.xml의 dependency에 다음과 같은 코드를 입력한다.

```xml
<!-- Spring -->
<dependency>
  <groupId>org.springframework</groupId>
  <artifactId>spring-context</artifactId>
  <version>${spring.version}</version>
</dependency>

<!-- Spring MVC -->
<dependency>
  <groupId>org.springframework</groupId>
  <artifactId>spring-webmvc</artifactId>
  <version>${spring.version}</version>
</dependency>`
```

DispatcherServlet에 대한 설정은 web.xml에서 하고 DispatcherServlet이 읽을 설정은 Java Config로 진행한다.



출처 : https://www.boostcourse.org/



