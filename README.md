# testTask0

по опциям "-i" / "-o" ожидается путь, соответственно ко входному/выходному файлу содержищему валидный json вида:
`````````````
{
  "value": 12,
  "children": [
   { 
      "value": 17,
      "children": [
                  {
                      "value": "1 2 3 5 8 13 21",
                      "children": []
                  },
                  {
                    "value": "some string",
                    "children": []
                  }
        
                  ]
    },
    {
      "value": "1 2 3 5 8 13 21",
      "children": [
        
      ]
    },
    {
      "value": "some string",
      "children": [
        
      ]
    },
    {
      "value": 2.71,
      "children": [
        
      ]
    }
  ]
}
`````````````
после прочтения файла на экран выводится построенное дерево в следующем виде:

``````````
value: 12
        value: 17
                value: "1 2 3 5 8 13 21"
                value: "some string"
        value: "1 2 3 5 8 13 21"
        value: "some string"
        value: 2.71
```````````


для работы с валидным json используется бибилиотека [@nlohman/json](https://github.com/nlohmann/json)
