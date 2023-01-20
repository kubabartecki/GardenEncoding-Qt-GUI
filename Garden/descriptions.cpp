#include "descriptions.h"

Descriptions::Descriptions()
{
    file_tab_desc = ("<br/>Obecnie jesteś w karcie **Plik**:\n\n"
                "- aby zmienić docelowe pliki kliknij \"Wybierz plik\"\n\n"
                "- wybierz odpowiednią opcję kodowania\n\n"
                "  jeśli chcemy otrzymać *kod* z pola zaznaczamy **\"Kodowanie\"**\n\n"
                "  a jeśli *pole* z kodu zaznaczamy **\"Dekodowanie\"**\n\n"
                "- klikamy w przycisk Koduj/Dekoduj\n\n\n");

    manual_tab_desc = ("<br/>Obecnie jesteś w karcie **Ustaw ręcznie**:\n\n"
                  "- możliwość edycji pola za pomocą kliknięcia,\n\n"
                  "  rozmiar pola regulujemy wartością potęgi\n"
                  "- możliwość wprowadzenia kodu w polu tekstowym\n\n"
                  "  Przykładowy kod:\n"
                  "  ```\n"
                  "  2 #1011\n"
                  "  ```\n"
                  "  brana pod uwagę jest tylko pierwsza linia\n\n"
                  "  do znaku \"\\n\"\n"
                  "- wybierz odpowiednią opcję kodowania\n\n"
                  "  jeśli chcemy otrzymać *kod* z pola zaznaczamy **\"Kodowanie\"**\n\n"
                  "  a jeśli *pole* z kodu zaznaczamy **\"Dekodowanie\"**\n\n"
                  "- klikamy w przycisk Koduj/Dekoduj\n\n"
                  "- wynik pojawia się na ekranie\n\n");

    single_field_desc = ("- pole \"Podanie kilku działek\" nie jest zaznaczone\n\n"
                         "  wynik pojawia się w pliku\n\n"
                         "  (jeśli potęga <= 15)\n\n"
                         "  oraz na ekaranie (jeśli potęga <= 6)\n\n\n"
                         "<br/>Przykładowy plik pola:\n\n"
                         "```\n"
                         "2\n"
                         "1100\n"
                         "1100\n"
                         "1111\n"
                         "1111\n"
                         "```\n"
                         "I jego rezultat:\n\n"
                         "```\n"
                         "2 #1011\n"
                         "```");

    multi_field_desc = ("- pole \"Podanie kilku działek\" jest zaznaczone\n\n"
                        "  wynik pojawia się tylko w pliku\n\n"
                        "  (jeśli potęga <= 15)\n\n"
                        "<br/>Przykładowy plik działek:\n\n\n"
                        "```\n"
                        "2\n"
                        "1100\n"
                        "1100\n"
                        "1111\n"
                        "1111\n"
                        "\n"
                        "1\n"
                        "11\n"
                        "11\n"
                        "```\n"
                        "I jego rezultat:\n\n"
                        "```\n"
                        "2 #1011\n"
                        "1 1\n"
                        "```");
}

QString Descriptions::get_file_tab_desc()
{
    return file_tab_desc;
}

QString Descriptions::get_manual_tab_desc()
{
    return manual_tab_desc;
}

QString Descriptions::get_single_field_desc()
{
    return single_field_desc;
}

QString Descriptions::get_multi_field_desc()
{
    return multi_field_desc;
}
