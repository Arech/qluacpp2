# qluacpp2
Short description in English: Fork of [elelel](https://github.com/elelel) 's projects [luacpp](https://github.com/elelel/luacpp) &amp; [qluacpp](https://github.com/elelel/qluacpp) with updates for my [t18qsrv](https://github.com/Arech/t18qsrv) proxy server for QUIK. If you are here just for using Lua from C++, look into original `luacpp` project, this one is too specialized for `t18qsrv`. 

Each subdirectory applies to relevant original project and bears it's own license as set by @elelel. MIT, like Lua for `luacpp` subdirectory and GPL v3.0 for `qluacpp`.

The rest text is in Russian, because most likely it won't ever be used by non-Russian speaking people as it's intended for use with Russian stock market.

-----

## Зачем?

Сравнительно недавно МосБиржа и затем QUIK реализовали то, что они называют 19-значные идентификаторы сделок. @elelel считает, что эти идентификаторы могут быть чем угодно, поэтому возвращает из как строки. Так же он заинтересован поддерживать совместимость своих проектов как с 64битными, так и с 32битными системами на старом Lua 5.1 (QUIK версий до 8.5) и новом Lua 5.3 (Квик после 8.5). Я считаю, что эти идентификаторы не могут быть ничем иным, кроме как `uint64`, который надо именно так возвращать и обрабатывать, а о Lua 5.1 и 32 разрядных системах можно давно забыть.

Меня корёжит от мысли возврата строк в нагруженном коде, которые потом надо всё равно конвертить в `uint64`, поэтому этот форк - базовая причина "зачем?". Чтобы уменьшить бессмысленную нагрузку на и так тормозной Квик с тормозным Луа. Кроме того, на момент форка оба проекта @elelel не полностью поддерживают Lua 5.3 и всё равно требуют правки. Иных принципиальных отличий сейчас нет и не планируются.

Если появится новая информация или @elelel внесёт аналогичные исправления, форк скорее всего будет удалён. В любом случае, сначала проверяйте оригиналы.

По сути этот форк просто часть моего проекта [t18qsrv](https://github.com/Arech/t18qsrv), вынесенная в отдельную репу по причине лицензионной несовместимости, плюс для лучшего мониторинга.

## Содержание

Первый комит репы - в точности оригинальные файлы [elelel](https://github.com/elelel), выкачанные на момент 22 марта 2021. Изменения поверх - мои.



