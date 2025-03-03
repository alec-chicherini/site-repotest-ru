// Note: to configure indentation & minification, define this at compile time
// before including HTML headers.
#define HTML_INDENTATION \
  2  ///< Default indentation can be set to 0 to remove many spaces in generated
     ///< HTML
#define HTML_ENDLINE \
  "\n"  ///< End of lines can be removed to minimize even more the resulting
        ///< generated HTML

#include <HTML/HTML.h>

#include <iostream>

int main() {
  HTML::Document document("repotest.ru");
  document.addAttribute("lang", "en");

  // Head
  document.head() << HTML::Meta("utf-8")
                  << HTML::Meta("viewport",
                                "width=device-width, initial-scale=1");
  document.head() << HTML::Rel("stylesheet",
                               "https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/"
                               "dist/css/bootstrap.min.css")
                         .integrity(
                             "sha384-"
                             "QWTKZyjpPEjISv5WaRU9OFeRpok6YctnYmDr5pNlyT2bRjXh0"
                             "JMhjY6hW+ALEwIH")
                         .crossorigin("anonymous");

  // Body
  document.body().cls("bg-white");

  // Content in a container
  HTML::Div main("container");
  main << HTML::Header1("repotest.ru").id("anchor_link_1");
  main << HTML::Paragraph("Это сайт моих экспериментов и пет проектов на C++")
              .style("font-family:monospace");
  main << HTML::Text("Исходный код всех проектов в ") << HTML::Break();
  main << HTML::Link("https://github.com/alec-chicherini",
                     "https://github.com/alec-chicherini")
              .cls("my_style");

  main << (HTML::Table().cls("table table-hover table-sm")
           << HTML::Caption("Ссылки на задеплоенные проекты")
           << (HTML::Row() << HTML::ColHeader("Ссылка")
                           << HTML::ColHeader("github.com")
                           << HTML::ColHeader("Описание")
                           << HTML::ColHeader("Технология"))
           << (HTML::Row()
               << (HTML::Col() << HTML::Link("repotest.ru",
                                             "https://repotest.ru/index.html"))
               << (HTML::Col()
                   << HTML::Link("pet-projects-production",
                                 "https://github.com/alec-chicherini/"
                                 "pet-projects-production"))
               << HTML::Col("Логика деплоя этого сайта")
               << (HTML::Col() << HTML::Link("https://www.docker.com/",
                                             "https://www.docker.com/")))
           << (HTML::Row()
               << (HTML::Col() << HTML::Link("repotest.ru",
                                             "https://repotest.ru/index.html"))
               << (HTML::Col() << HTML::Link(
                       "site-repotest-ru",
                       "https://github.com/alec-chicherini/site-repotest-ru"))
               << HTML::Col("Этот сайт")
               << (HTML::Col()
                   << HTML::Link("https://github.com/SRombauts/HtmlBuilder",
                                 "https://github.com/SRombauts/HtmlBuilder")))
           << (HTML::Row()
               << (HTML::Col() << HTML::Link("repotest.ru",
                                             "https://repotest.ru/index.html"))
               << (HTML::Col() << HTML::Link(
                       "server-http",
                       "https://github.com/alec-chicherini/server-http"))
               << HTML::Col("HTTP сервер")
               << (HTML::Col()
                   << HTML::Link("userver", "https://userver.tech/")))
           << (HTML::Row()
               << (HTML::Col()
                   << HTML::Link("https://wordle-client-qt-25-02.repotest.ru",
                                 "https://wordle-client-qt-25-02.repotest.ru/"
                                 "wordle-client-qt.html"))
               << (HTML::Col() << HTML::Link(
                       "wordle-client-qt",
                       "https://github.com/alec-chicherini/wordle-client-qt"))
               << HTML::Col(
                      "Игра wordle-task в wasm. Версия 25.02 standalone")
               << (HTML::Col() << HTML::Link(
                       "Qt6 Web Assembly", "https://doc.qt.io/qt-6/wasm.html")))
           << (HTML::Row() << (HTML::Col() << HTML::Link(
                                   "https://wordle-client-qt-25-03.repotest.ru",
                                   "https://wordle-client-qt-25-03.repotest.ru/"
                                   "wordle-client-qt.html"))
                           << (HTML::Col() << HTML::Link(
                                   "wordle-client-qt",
                                   "https://github.com/alec-chicherini/"
                                   "wordle-client-qt"))
                           << HTML::Col(
                                  "Игра wordle-task в wasm. Версия 25.03 для "
                                  "микросервисов")
                           << (HTML::Col() << HTML::Link(
                                   "Qt6 Web Assembly",
                                   "https://doc.qt.io/qt-6/wasm.html"))));

  main << HTML::Small("Copyright Chicherin Alexey @ 2025");

  main << HTML::Link().id("anchor_link_2");

  document << std::move(main);

  // Javascript at the end of the body
  document << HTML::Script(
                  "https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/js/"
                  "bootstrap.bundle.min.js")
                  .integrity(
                      "sha384-"
                      "YvpcrYf0tY3lHB60NNkmXc5s9fDVZLESaAA55NDzOxhy9GkcIdslK1eN"
                      "7N6jIeHz")
                  .crossorigin("anonymous");
  document << HTML::Script(
                  "https://cdn.jsdelivr.net/npm/@popperjs/core@2.11.8/dist/umd/"
                  "popper.min.js")
                  .integrity(
                      "sha384-I7E8VVD/ismYTF4hNIPjVp/Zjvgyol6VFvRkX/"
                      "vR+Vc4jQkC+hVqc2pM8ODewa9r")
                  .crossorigin("anonymous");
  document << HTML::Script(
                  "https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/js/"
                  "bootstrap.min.js")
                  .integrity(
                      "sha384-"
                      "0pUGZvbkm6XF6gxjEnlmuGrJXVbNuzT9qBBavbLwCsOGabYfZo0T0to5"
                      "eqruptLy")
                  .crossorigin("anonymous");

  std::cout << document;
  return 0;
}
