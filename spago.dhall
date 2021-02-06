{ name = "unfoldable"
, dependencies =
  [ "foldable-traversable"
  , "maybe"
  , "partial"
  , "prelude"
  , "tuples"
  , "assert"
  , "console"
  ]
, packages = ../pure-c/package-sets/packages.dhall
, sources = [ "src/**/*.purs", "test/**/*.purs" ]
}
