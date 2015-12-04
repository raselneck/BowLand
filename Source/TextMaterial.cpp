#include "TextMaterial.hpp"
#include "GameObject.hpp"

using namespace DirectX;

// Creates a new text material
TextMaterial::TextMaterial( GameObject* gameObject )
    : Material( gameObject )
{
    // Load the default vertex and pixel shaders
    assert( _vertexShader->LoadShaderFile( L"Shaders\\PixelVertexShader.cso" ) );
    assert( _pixelShader->LoadShaderFile( L"Shaders\\PixelPixelShader.cso" ) );
}

// Destroys this text material
TextMaterial::~TextMaterial()
{
}

// Gets the color to render the text as
XMFLOAT4 TextMaterial::GetTextColor() const
{
    return _textColor;
}

// Sets the color to render the text as
void TextMaterial::SetTextColor( const XMFLOAT4& color )
{
    _textColor = color;
}

// Sends this material's information to the shaders
void TextMaterial::UpdateShaderData()
{
    // TODO - Set camera projection / view

    // Send our variables
    assert( _pixelShader->SetFloat4( "TextColor", _textColor ) );

    // Let the base class do its thing
    Material::UpdateShaderData();
}